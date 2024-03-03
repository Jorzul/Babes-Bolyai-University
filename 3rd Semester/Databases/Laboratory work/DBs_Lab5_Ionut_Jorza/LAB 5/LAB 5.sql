USE [CSGO Matches]
GO

/* Table Ta */
CREATE TABLE Ta_Players 
	(Ta_ID INT PRIMARY KEY,
	Ta_PlayerRating INT UNIQUE,
	Ta_PlayerHours INT
	);

/* Table Tb */
CREATE TABLE Tb_Teams
	(Tb_ID INT PRIMARY KEY,
	Tb_TeamSalary INT,
	Tb_TeamPlacement INT
	)

/* Table Tc */
CREATE TABLE Tc_TeamsPlayers
	(Tc_ID INT PRIMARY KEY,
	Ta_ID INT FOREIGN KEY REFERENCES Ta_Players(Ta_ID),
	Tb_ID INT FOREIGN KEY REFERENCES Tb_Teams(Tb_ID),
	)

/*
INSERT INTO Ta_Players(Ta_ID, Ta_PlayerName, Ta_PlayerRating)
VALUES (1, 'Player1', 62),
	(2, 'Player2', 77),
	(3, 'Player3', 87),
	(4, 'Player4', 70),
	(5, 'Player5', 81),
	(6, 'Player6', 40),
	(7, 'Player7', 50),
	(8, 'Player8', 79),
	(9, 'Player9', 89),
	(10, 'Player10', 65),
	(11, 'Player11', 82),
	(12, 'Player12', 37),
	(13, 'Player13', 46),
	(14, 'Player14', 12),
	(15, 'Player15', 43),
	(16, 'Player16', 75),
	(17, 'Player17', 43),
	(18, 'Player18', 85),
	(19, 'Player19', 87),
	(20, 'Player20', 70)

INSERT INTO Tb_Teams(Tb_ID, Tb_TeamName, Tb_TeamPlacement)
VALUES (1, 'Team1', 1),
		(2, 'Team2', 2),
		(3, 'Team3', 3),
		(4, 'Team4', 4),
		(5, 'Team5', 5),
		(6, 'Team6', 6),
		(7, 'Team7', 7),
		(8, 'Team8', 8),
		(9, 'Team9', 9),
		(10, 'Team10', 10),
		(11, 'Team11', 11),
		(12, 'Team12', 12),
		(13, 'Team13', 13),
		(14, 'Team14', 14),
		(15, 'Team15', 15),
		(16, 'Team16', 16),
		(17, 'Team17', 17),
		(18, 'Team18', 18),
		(19, 'Team19', 19),
		(20, 'Team20', 20)

INSERT INTO Tc_TeamsPlayers(Tc_ID, Ta_ID, Tb_ID, total_wins)
VALUES (1, 1, 1, 3),
		(2, 2, 1, 3),
		(3, 3, 1, 3),
		(4, 4, 1, 3),
		(5, 5, 1, 3),
		(6, 6, 2, 10),
		(7, 7, 2, 10),
		(8, 8, 2, 10),
		(9, 9, 2, 10),
		(10, 10, 2, 10),
		(11, 11, 3, 7),
		(12, 12, 3, 7)
*/

GO
CREATE OR ALTER PROCEDURE insertIntoTa(@int INT) as
	DECLARE @max INT
	SET @max = @int * 2 + 100
	WHILE @int > 0 
	BEGIN
		INSERT INTO Ta_Players VALUES(@int, @max, @int%150)
		SET @int = @int - 1
		SET @max = @max - 2
	END


GO
CREATE OR ALTER PROCEDURE insertIntoTb(@int INT) as
	WHILE @int > 0 BEGIN
		INSERT INTO Tb_Teams VALUES (@int, @int%705, @int%125)
		SET @int = @int - 1
	END


GO
CREATE OR ALTER PROCEDURE insertIntoTc(@int INT) as
	DECLARE @aid INT
	DECLARE @bid INT
	WHILE @int > 0 BEGIN
		SET @aid = (SELECT TOP 1 Ta_ID FROM Ta_Players ORDER BY NEWID())
		SET @bid = (SELECT TOP 1 Tb_ID FROM Tb_Teams ORDER BY NEWID())
		INSERT INTO Tc_TeamsPlayers VALUES (@int, @aid, @bid)
		SET @int = @int - 1
	END


EXEC insertIntoTa 10000
EXEC insertIntoTb 15000
EXEC insertIntoTc 3000

DELETE FROM Tc_TeamsPlayers
DELETE FROM Ta_Players
DELETE FROM Tb_Teams

SELECT * FROM Ta_Players
SELECT * FROM Tb_Teams
SELECT * FROM Tc_TeamsPlayers

DROP TABLE Ta_Players
DROP TABLE Tb_Teams
DROP TABLE Tc_TeamsPlayers



/* A) */

/*Clustered Index Scan */
SELECT * FROM Ta_Players WHERE Ta_ID > 7000     -- The clustered index scan is used when retrieving a range of rows based on the clustered index.

/* Clustered Index Seek */
SELECT * FROM Ta_Players WHERE Ta_ID = 1201     -- The clustered index seek is used when searching for a specific key in the clustered index.

/* Nonclustered Index Scan */
SELECT * FROM Ta_Players WHERE Ta_PlayerRating > 1000      -- The nonclustered index scan is used when the condition involves a column not part of the clustered index.

/* Nonclustered Index Seek */
SELECT * FROM Ta_Players WHERE Ta_PlayerHours = 100       --  The nonclustered index seek is used when searching for a specific key in a nonclustered index.

/* Key Lookup */
SELECT Ta_PlayerRating FROM Ta_Players WHERE Ta_ID = 1201     -- The key lookup occurs when columns not included in the nonclustered index need to be retrieved from the clustered index.


/* B) */

SELECT * FROM Tb_Teams where Tb_TeamSalary = 750 -- 0.04 cost
-- If we run this query without an index the program has to perform a table scan (it needs to go through all the rows)

CREATE NONCLUSTERED INDEX Salary_INDX on Tb_Teams(Tb_TeamSalary) include (Tb_ID, Tb_TeamPlacement)
DROP INDEX Salary_INDX ON Tb_Teams

-- Instead of scanning the entire table, SQL Server can perform an index seek on the nonclustered index and that's why it's faster.
-- At the same time, by using 'include (Tb_ID, Tb_TeamPlacement)' the query can retrieve these columns directly from the index without having to look it up in the database.

SELECT * FROM Tb_Teams where Tb_TeamSalary = 750   -- 0.003 cost

/* C) */

GO
CREATE OR ALTER VIEW view1 AS
    SELECT TOP 1000 T1.Ta_PlayerHours, T2.Tb_TeamSalary
    FROM Tc_TeamsPlayers T3 join Ta_Players T1 on T3.Ta_ID = T1.Ta_ID join Tb_Teams T2 on T3.Tb_ID = T2.Tb_ID
    where T2.Tb_TeamSalary > 500 and T1.Ta_PlayerHours < 15

select * from view1