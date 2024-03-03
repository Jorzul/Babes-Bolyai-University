	USE [CSGO Matches]
GO

/*
CREATE OR ALTER VIEW TeamSponsors AS
SELECT T.Team_Name, S.Sponsor_Name
FROM Team T INNER JOIN Team_Sponsor TS ON T.Team_ID = TS.Team_ID
	INNER JOIN Sponsor S ON S.Sponsor_ID = TS.Sponsor_ID
WHERE T.Team_Rating > 25

CREATE OR ALTER VIEW TeamNameForRating AS
SELECT T.Team_Name
FROM Team T
WHERE T.Team_Rating > 30

CREATE OR ALTER VIEW SponsorOriginForTeams AS
SELECT S.Sponsor_Origin
FROM Sponsor S INNER JOIN Team_Sponsor TS ON TS.Sponsor_ID = S.Sponsor_ID
	INNER JOIN Team T ON T.Team_ID = TS.Team_ID
WHERE T.World_Ranking < 7

SELECT * FROM RatingWinPercentage
SELECT * FROM TeamSponsors

INSERT [Tables] VALUES
	('Team'),
	('Sponsor'),
	('Team_Sponsor')

INSERT Tests VALUES
	('Test1'),
	('Test2'),
	('Test3')

INSERT TestTables VALUES
	(3, 3, 50, 1),
	(1, 2, 250, 2),
	(1, 3, 40, 1),
	(3, 1, 150, 3),
	(3, 2, 330, 2),
	(1, 1, 210, 3)

INSERT [Views] VALUES
	('TeamNameForRating'),
	('TeamSponsors'),
	('SponsorOriginForTeams')


INSERT TestViews VALUES
	(2, 1),
	(3, 1),
	(2, 2),
	(3, 2),
	(2, 3),
	(3, 3)

SELECT * FROM TestViews
*/

CREATE OR ALTER PROCEDURE uspRunTest(@TestName VARCHAR(100))
AS
	-- Get Starting Time
	DECLARE @StartTime DATETIME = SYSDATETIME()

	INSERT TestRuns([Description], StartAt) VALUES (@TestName, @StartTime)

	-- Get the TestRun ID
	DECLARE @TestRunID INT
	SELECT @TestRunID = IDENT_CURRENT('TestRuns')
	-- PRINT(@TestRunID)

	-- Get Test ID
	DECLARE @TestID INT
	SELECT @TestID = t.TestID
	FROM Tests t
	WHERE t.Name = @TestName

	-- Initiate cursor to iterate over the tables in our test
	DECLARE @TableName VARCHAR(100)
	DECLARE NameCursor CURSOR FOR
		SELECT ta.Name
		FROM TestTables t INNER JOIN [Tables] ta
		ON t.TestID = @TestID AND ta.TableID = t.TableID
		ORDER BY t.Position

	OPEN NameCursor
	FETCH NEXT FROM NameCursor
		INTO @TableName

	-- Using the cursor delete everything from the tables
	WHILE @@FETCH_STATUS = 0
	BEGIN
		DECLARE @sqlDel VARCHAR(100) = 'DELETE FROM ' + @TableName
		EXEC(@sqlDel)
		FETCH NEXT FROM NameCursor
			INTO @TableName
	END
	
	-- Reinitialise the cursor, with the elements in opposite order
	CLOSE NameCursor
	DEALLOCATE NameCursor
	DECLARE NameCursor CURSOR FOR
		SELECT ta.Name, ta.TableID, t.NoOfRows
		FROM TestTables t INNER JOIN [Tables] ta
		ON t.TestID = @TestID AND ta.TableID = t.TableID
		ORDER BY t.Position DESC

	-- Getting the data from the table for the first time
	DECLARE @RowCount INT
	DECLARE @TableID INT
	OPEN NameCursor
	FETCH NEXT FROM NameCursor
		INTO @TableName, @TableID, @RowCount
	
	DECLARE @TableStartTime DATETIME
	DECLARE @TableEndTime DATETIME

	-- Insert into each of the tables using the 'uspInsertTable' procedure
	WHILE @@FETCH_STATUS = 0
	BEGIN
		-- PRINT (@TableID)
		
		SET @TableStartTime = SYSDATETIME()

		exec uspInsertTable @TableName, @RowCount
		
		SET @TableEndTime = SYSDATETIME()

		INSERT TestRunTables VALUES (@TestRunID, @TableID, @TableStartTime, @TableEndTime)
		FETCH NEXT FROM NameCursor
			INTO @TableName, @TableID, @RowCount
	END

	CLOSE NameCursor
	DEALLOCATE NameCursor
	DECLARE NameCursor CURSOR FOR
		SELECT vi.Name, vi.ViewID
		FROM TestViews v INNER JOIN [Views] vi
		ON v.TestID = @TestID AND v.ViewID = vi.ViewID

	DECLARE @ViewName varchar(100)
	DECLARE @ViewID INT
	OPEN NameCursor
	FETCH NEXT FROM NameCursor
		INTO @ViewName, @ViewID

	DECLARE @ViewStartTime DATETIME
	DECLARE @ViewEndTime DATETIME
	WHILE @@FETCH_STATUS = 0
	BEGIN
		SET @ViewStartTime = SYSDATETIME() 

		DECLARE @sqlSelect VARCHAR(MAX) = 'SELECT * FROM ' + @ViewName
		EXEC(@sqlSelect)

		SET @ViewEndTime = SYSDATETIME()

		INSERT TestRunViews VALUES (@TestRunID, @ViewID, @ViewStartTime, @ViewEndTime)
		FETCH NEXT FROM NameCursor
			INTO @ViewName, @ViewID
	END

	CLOSE NameCursor
	DEALLOCATE NameCursor

	-- Get the end time
	DECLARE @EndTime DATETIME = SYSDATETIME()

	UPDATE TestRuns
	SET EndAt = @EndTime
	WHERE TestRunID = @TestRunID
GO

CREATE OR ALTER PROCEDURE uspInsertTable(@TableName VARCHAR(100), @NoRows INT)
AS
	-- PRINT (@TableName)
	DECLARE @ColumnName VARCHAR(100)
	DECLARE @ColumnType VARCHAR(100)
	DECLARE ColumnCursor SCROLL CURSOR FOR
		SELECT c.name, t.name
		FROM sys.objects o INNER JOIN sys.columns c ON o.object_id = c.object_id
			INNER JOIN sys.types t ON t.user_type_id = c.user_type_id
		WHERE o.type = 'U' AND o.name = @TableName

	OPEN ColumnCursor
	FETCH NEXT FROM ColumnCursor
		INTO @ColumnName, @ColumnType

	DECLARE @Iteration INT = 0
	DECLARE @PrimaryIndex INT = 0

	DECLARE @sqlInsert VARCHAR(MAX) = 'INSERT ' + @TableName + ' VALUES '
	WHILE @Iteration < @NoRows
	BEGIN
		FETCH FIRST FROM ColumnCursor
			INTO @ColumnName, @ColumnType
		
		SET @sqlInsert = @sqlInsert + '('
		WHILE @@FETCH_STATUS = 0
		BEGIN		
			IF @ColumnType = 'int'
			BEGIN
				DECLARE @ForeignKeyCheck BIT = dbo.CheckIfColumnIsAForeignKey(@TableName,@ColumnName)
				DECLARE @PrimaryKeyCheck BIT = dbo.CheckIfColumnIsAPrimaryKey(@TableName,@ColumnName)

				IF @ForeignKeyCheck = 1
				BEGIN
					DECLARE @ForeignTable VARCHAR(50)

					SELECT @ForeignTable = OBJECT_NAME (f.referenced_object_id)
					FROM sys.foreign_keys AS f  
						INNER JOIN sys.foreign_key_columns AS fc   
					ON f.object_id = fc.constraint_object_id   
					WHERE f.parent_object_id = OBJECT_ID(@TableName) AND COL_NAME(fc.referenced_object_id, fc.referenced_column_id) = @ColumnName

					DECLARE @ForeignKeyValue INT
					DECLARE @ForeignKeyQuery NVARCHAR(100) = 'SELECT TOP 1 @ForeignKeyValue = ' + @ColumnName + ' FROM ' + @ForeignTable + ' ORDER BY NEWID()';
					EXEC sp_executesql @ForeignKeyQuery, N'@ForeignKeyValue INT OUTPUT', @ForeignKeyValue OUTPUT

					SET @sqlInsert = @sqlInsert + CONVERT(varchar, @ForeignKeyValue)
				END
				ELSE IF @PrimaryKeyCheck = 1
				BEGIN
					SET @sqlInsert = @sqlInsert + CONVERT(varchar, @PrimaryIndex)
					SET @PrimaryIndex = @PrimaryIndex + 1
				END
				ELSE
					SET @sqlInsert = @sqlInsert + dbo.RandomNumberBetween(1,50)
			END

			ELSE IF @ColumnType = 'varchar'
				SET @sqlInsert = @sqlInsert + '''' + @TableName + dbo.RandomNumberBetween(0, 10000) + ''''

			ELSE IF @ColumnType = 'date' OR @ColumnType = 'datetime'
			BEGIN
				DECLARE @ChosenMonth VARCHAR(2) = dbo.RandomNumberBetween(1, 12)
				DECLARE @ChosenDay VARCHAR(2) = dbo.RandomNumberBetween(1, 28)
				DECLARE @ChosenYear VARCHAR(4) = dbo.RandomNumberBetween(2000, 2023)

				DECLARE @DateString VARCHAR(100) = @ChosenMonth + '/' + @ChosenDay + '/' + @ChosenYear
				SET @sqlInsert = @sqlInsert + '''' + @DateString + ''''
			END

			FETCH NEXT FROM ColumnCursor
				INTO @ColumnName, @ColumnType

			IF @@FETCH_STATUS = 0
				SET	 @sqlInsert = @sqlInsert + ','
		END
		SET @sqlInsert = @sqlInsert + ')'
		SET @Iteration = @Iteration + 1
		IF @Iteration != @NoRows
			SET @sqlInsert = @sqlInsert + ','
	END

	print(@sqlInsert)
	exec(@sqlInsert)

	CLOSE ColumnCursor
	DEALLOCATE ColumnCursor
GO

EXEC uspRunTest 'Test3'

/*
SELECT * FROM TestRuns
SELECT * FROM TestRunTables
SELECT * FROM TestRunViews

SELECT * FROM Team


DELETE FROM Player
*/
