USE [practicExam]
GO

/* Subiectul II */
/* Subpunctul 1 */

CREATE TABLE Tents
	(TID INT PRIMARY KEY,
	TName VARCHAR(50) UNIQUE,
	TColor VARCHAR(50))

CREATE TABLE Guests
	(GID INT PRIMARY KEY,
	GName VARCHAR(50),
	GDateOfBirth DATE,
	TID INT REFERENCES Tents(TID))

CREATE TABLE Bands
	(BID INT PRIMARY KEY,
	BName VARCHAR(50),
	BGenre VARCHAR(50),
	BFee INT,
	TID INT REFERENCES Tents(TID),
	BStartPerf TIME,
	BEndPerf TIME)

CREATE TABLE Caterers
	(CID INT PRIMARY KEY,
	CName VARCHAR(50),
	CAddress VARCHAR(100),
	VeganMenu BIT)

CREATE TABLE TentCaterers
	(TID INT REFERENCES Tents(TID),
	CID INT REFERENCES Caterers(CID),
	PRIMARY KEY(TID, CID))

SELECT * FROM Tents
SELECT * FROM Guests
SELECT * FROM Bands
SELECT * FROM Caterers
SELECT * FROM TentCaterers

/*
DROP TABLE TentCaterers
DROP TABLE Caterers
DROP TABLE Bands
DROP TABLE Guests
DROP TABLE Tents
*/

INSERT Tents VALUES(1, 't1', 't1color'), (2, 't2', 't2color')
INSERT Guests VALUES(1, 'g1', '2003-01-12', 1), (2, 'g2', '2003-02-10', 2)
INSERT Bands VALUES(1, 'b1', 'b1genre', 100, 1, '10:00', '10:05')
INSERT Caterers VALUES(1, 'c1', 'c1address', 1), (2, 'c2', 'c2address', 0)
INSERT TentCaterers VALUES(1, 1), (1, 2), (2, 1)


/* Subpunctul 2 */

GO
CREATE OR ALTER PROCEDURE uspReassignTents
	(@N1 VARCHAR(50), @N2 VARCHAR(50))
AS
	DECLARE @TID1 INT = (SELECT TID FROM Tents WHERE TName = @N1)
	DECLARE @TID2 INT = (SELECT TID FROM Tents WHERE TName = @N2)

	IF EXISTS (SELECT * FROM Guests G WHERE G.TID = @TID1)
		UPDATE Guests
		SET TID = @TID2
		WHERE TID = @TID1

	IF EXISTS (SELECT * FROM Bands B WHERE B.TID = @TID1)
		UPDATE Bands
		SET TID = @TID2
		WHERE TID = @TID1

	DELETE FROM TentCaterers WHERE TID = @TID1
	DELETE FROM Tents WHERE TID = @TID1


EXEC uspReassignTents 't1', 't2'

/* Subpunctul 3 */

GO
CREATE OR ALTER VIEW vBandsWithAtleast50Guests
AS
	SELECT b.BName
	FROM Bands b
	WHERE b.TID IN
		(SELECT g.TID
		FROM Guests g
		GROUP BY g.TID
		HAVING COUNT(*) > 1
		)

SELECT * FROM vBandsWithAtleast50Guests

/* Subpunctul 4 */

GO
CREATE OR ALTER FUNCTION ufFilterCaterers(@T INT, @providesVegMenu BIT)
RETURNS TABLE
RETURN
	SELECT c.CName
	FROM Caterers c
	WHERE c.CID IN
		(SELECT tc.CID
		FROM TentCaterers tc
		GROUP BY tc.CID
		HAVING COUNT(tc.TID) > @T) AND c.VeganMenu = @providesVegMenu

SELECT *
FROM ufFilterCaterers(1, 1)