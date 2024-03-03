USE [examPrac]
GO

/* Subiectul II */
/* Subpunctul 1. */

DROP TABLE RoutesStations
DROP TABLE Stations
DROP TABLE [Routes]
DROP TABLE Trains
DROP TABLE TrainTypes

CREATE TABLE TrainTypes
	(TTID INT PRIMARY KEY,
	TTName VARCHAR(50),
	TTDescr VARCHAR(200))

CREATE TABLE Trains
	(TID INT PRIMARY KEY,
	TName VARCHAR(50),
	TTID INT REFERENCES TrainTypes(TTID))

CREATE TABLE [Routes]
	(RID INT PRIMARY KEY,
	RName VARCHAR(50) UNIQUE,
	TID INT REFERENCES Trains(TID))

CREATE TABLE Stations
	(SID INT PRIMARY KEY,
	SName VARCHAR(50) UNIQUE)

CREATE TABLE RoutesStations
	(RID INT REFERENCES [Routes](RID),
	SID INT REFERENCES Stations(SID),
	Arrival TIME,
	Departure TIME,
	PRIMARY KEY(RID, SID))

INSERT TrainTypes VALUES(1, 'tt1', 'tt1desc'), (2, 'tt2', 'tt2desc')
INSERT Trains VALUES(1, 't1', 1), (2, 't2', 1), (3, 't3', 1)
INSERT [Routes] VALUES(1, 'r1', 1), (2, 'r2', 2), (3, 'r3', 3)
INSERT Stations VALUES(1, 's1'), (2, 's2'), (3, 's3')

SELECT * FROM TrainTypes
SELECT * FROM Trains
SELECT * FROM [Routes]
SELECT * FROM Stations

/* Subpunctul 2. */

GO
CREATE OR ALTER PROCEDURE uspUpdateStationOnRoute 
		(@RName VARCHAR(50), @SName VARCHAR(50), @Arrival TIME, @Departure TIME)
AS
	DECLARE @RID INT = (SELECT RID FROM [Routes] WHERE RName = @RName)
	DECLARE @SID INT = (SELECT SID FROM Stations WHERE SName = @SName)

	IF @RID IS NULL BEGIN
		RAISERROR('route doesnt exist', 16, 1)
		RETURN
	END

	IF @SID IS NULL BEGIN
		RAISERROR('station doesnt exist', 16, 1)
		RETURN
	END

	IF EXISTS (SELECT * FROM RoutesStations WHERE RID = @RID AND SID = @SID)
		UPDATE RoutesStations
		SET Arrival = @Arrival, Departure = @Departure
		WHERE RID = @RID AND SID = @SID
	ELSE
		INSERT RoutesStations(RID, SID, Arrival, Departure)
		VALUES (@RID, @SID, @Arrival, @Departure)

-- uspUpdateStationOnRoute 'r4', 's1', '10:00', '10:05' -- error route does not exist
-- uspUpdateStationOnRoute 'r1', 's4', '10:00', '10:05' -- error station does not exist

EXEC uspUpdateStationOnRoute 'r1', 's1', '10:00', '10:05'
EXEC uspUpdateStationOnRoute 'r1', 's2', '10:10', '10:15'
EXEC uspUpdateStationOnRoute 'r1', 's3', '10:20', '10:25'
EXEC uspUpdateStationOnRoute 'r2', 's1', '10:00', '10:05'
EXEC uspUpdateStationOnRoute 'r2', 's2', '10:10', '10:15'
EXEC uspUpdateStationOnRoute 'r2', 's3', '10:20', '10:25'
EXEC uspUpdateStationOnRoute 'r3', 's1', '11:55', '11:59'

SELECT * FROM RoutesStations

/* Subpunctul 3. */

GO
CREATE VIEW vRoutesWithAllStations
AS
	SELECT r.RName
	FROM [Routes] r
	WHERE NOT EXISTS
		(SELECT SID
		FROM Stations
		EXCEPT
		SELECT SID
		FROM RoutesStations
		WHERE RID = r.RID)

SELECT * FROM vRoutesWithAllStations

/* Subpunctul 4. */

GO
CREATE FUNCTION ufFilterStationsByNumOfRoutes(@R INT)
RETURNS TABLE
RETURN
	SELECT s.SName
	FROM Stations s
	WHERE s.SID IN
		(SELECT rs.SID
		FROM RoutesStations rs
		GROUP BY rs.SID
		HAVING COUNT(*) > @R)

SELECT *
FROM ufFilterStationsByNumOfRoutes(2)