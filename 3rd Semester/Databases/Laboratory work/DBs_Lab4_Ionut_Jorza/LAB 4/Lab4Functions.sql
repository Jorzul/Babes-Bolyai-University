USE [CSGO Matches]
GO

CREATE OR ALTER VIEW getRANDValue
AS
SELECT RAND() AS Value

GO
CREATE OR ALTER FUNCTION RandomNumberBetween(@lower INT, @upper INT)
RETURNS VARCHAR(10)
AS
BEGIN
	DECLARE @result INT
	DECLARE @range INT = @upper - @lower + 1
	SET @result = FLOOR((SELECT Value FROM getRANDValue) * @range + @lower)
	RETURN @result
END

GO
CREATE OR ALTER FUNCTION CheckIfColumnIsAForeignKey(@table_name VARCHAR(50), @column_name VARCHAR(50))
RETURNS BIT
AS 
BEGIN
	IF( EXISTS(
		SELECT *
		FROM INFORMATION_SCHEMA.REFERENTIAL_CONSTRAINTS RC
			JOIN INFORMATION_SCHEMA.KEY_COLUMN_USAGE KCU
			ON RC.CONSTRAINT_CATALOG = KCU.CONSTRAINT_CATALOG
				AND RC.CONSTRAINT_NAME = KCU.CONSTRAINT_NAME
		WHERE KCU.TABLE_NAME = @table_name AND KCU.COLUMN_NAME = @column_name
			)
		)
		RETURN 1
	RETURN 0
END

GO
CREATE OR ALTER FUNCTION CheckIfColumnIsAPrimaryKey(@table_name VARCHAR(50), @column_name VARCHAR(50))
RETURNS BIT
AS 
BEGIN
	DECLARE @PrimaryName VARCHAR(100)
	DECLARE PrimaryCursor CURSOR FOR
		SELECT c.name
			FROM sys.tables t INNER JOIN sys.indexes i ON t.object_id = i.object_id
				INNER JOIN sys.index_columns ic ON i.object_id = ic.object_id
			AND i.index_id = ic.index_id
				INNER JOIN sys.columns c ON ic.object_id = c.object_id
			AND ic.column_id = c.column_id
			WHERE i.is_primary_key = 1 AND t.name = @table_name

	OPEN PrimaryCursor
	FETCH NEXT FROM PrimaryCursor
		INTO @PrimaryName

	DECLARE @PrimaryKeyCheck BIT = 0
	WHILE @@FETCH_STATUS = 0
	BEGIN
		IF @column_name = @PrimaryName
		BEGIN
			CLOSE PrimaryCursor
			DEALLOCATE PrimaryCursor
			RETURN 1
		END

		FETCH NEXT FROM PrimaryCursor
			INTO @PrimaryName
	END

	CLOSE PrimaryCursor
	DEALLOCATE PrimaryCursor
	RETURN 0
END

/*
IF @PrimaryKeyCheck = 1
					BEGIN
						DECLARE @ForeignNPrimary BIT
						DECLARE @ForeignNPrimaryQuery VARCHAR(100) = 'SELECT * FROM ' + @ForeignTable + ' WHERE ' + @ColumnName + ' = ' + CONVERT(VARCHAR, @ForeignKeyValue)
						PRINT(@ForeignNPrimaryQuery)
						EXEC(@ForeignNPrimaryQuery)

						PRINT('HELLO')
						IF @@ROWCOUNT > 0
							SET @ForeignNPrimary = 1
						ELSE
							SET @ForeignNPrimary = 0

						WHILE @ForeignNPrimary = 1
						BEGIN
							EXEC sp_executesql @ForeignKeyQuery, N'@ForeignKeyValue INT OUTPUT', @ForeignKeyValue OUTPUT
							
							SET @ForeignNPrimaryQuery = 'SELECT * FROM ' + @ForeignTable + ' WHERE ' + @ColumnName + ' = ' + @ForeignKeyValue
							EXEC(@ForeignNPrimaryQuery)

							IF @@ROWCOUNT <= 0
								SET @ForeignNPrimary = 0
						END
					END
*/