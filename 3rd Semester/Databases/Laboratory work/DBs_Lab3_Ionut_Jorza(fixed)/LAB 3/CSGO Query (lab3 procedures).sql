USE [CSGO Matches]
GO

/* 
Version 0
The version we currently have after the first 2 labs.
*/


/*
Version 1
Adds/deletes a 'fans' table, which is a table with fans from a particular point of the world.
*/


CREATE PROCEDURE uspAddTableFans AS
	CREATE TABLE Fans
	(Fans_ID INT PRIMARY KEY,
	Fans_Name CHAR(10),
	Fans_Number INT,
	Fans_Nationality VARCHAR(50)
	)
GO

CREATE PROCEDURE uspDropTableFans AS
	DROP TABLE Fans
GO


/*
Version 2
Modifies the column 'Fans_Name' such that it becomes VARCHAR.
*/


CREATE PROCEDURE uspChangeColumnFans_Name AS
	ALTER TABLE Fans
	ALTER COLUMN Fans_Name VARCHAR(50)
GO


CREATE PROCEDURE uspBackChangeColumnFans_Name AS
	ALTER TABLE Fans
	ALTER COLUMN Fans_Name CHAR(10)
GO


/*
Version 3
Adds/deletes a 'fanbase' table for a team, which is a separated table that contains a fanbase.
*/


CREATE PROCEDURE uspAddTableFanbase AS
	CREATE TABLE Fanbase(Fanbase_Nationality VARCHAR(50))
GO


CREATE PROCEDURE uspDropTableFanbase AS
	DROP TABLE Fanbase
GO


/*
Version 4
Adds/deletes foreigns keys team_ID (from Team) and fans_ID (from Fans) to the 'fanbase' table.
*/


CREATE PROCEDURE uspAddFKtoFanbase AS
	ALTER TABLE Fanbase
	ADD Team_ID INT CONSTRAINT FK_FANBASE_TEAM REFERENCES Team(Team_ID),
		Fans_ID INT CONSTRAINT FK_FANBASE_FANS REFERENCES Fans(Fans_ID)
GO


CREATE PROCEDURE uspDropFKfromFanbase AS
	ALTER TABLE Fanbase
	DROP FK_FANBASE_TEAM, FK_FANBASE_FANS,
		COLUMN Team_ID, Fans_ID
GO


/*
Version 5
Creates/deletes a primary key to 'fanbase' table that is made out of team_ID and fans_ID.
*/


CREATE PROCEDURE uspCreatePKforFanbase AS
	ALTER TABLE Fanbase
	ADD Fanbase_ID INT CONSTRAINT PK_FANBASE_ID PRIMARY KEY
GO


CREATE PROCEDURE uspDropPKforFanbase AS
	ALTER TABLE Fanbase
	DROP PK_FANBASE_ID,
		COLUMN Fanbase_ID
GO

/*
SELECT * 
FROM SYS.OBJECTS
WHERE TYPE = 'PK'
ORDER BY create_date DESC
*/

/*
Version 6
Adds/deletes a foreign key to the 'fanbase' table, which is the map they enjoy watching the most (from Map: Map_ID)
*/


CREATE PROCEDURE uspAddFKMaptoFanbase AS
	ALTER TABLE Fanbase
	ADD Map_ID INT CONSTRAINT FK_FANBASE_MAP REFERENCES Map(Map_ID)
GO


CREATE PROCEDURE uspDropFKMaptoFanbase AS
	ALTER TABLE Fanbase
	DROP FK_FANBASE_MAP,
		COLUMN Map_ID
GO


/*
Version 7
Modifies the column 'Fans_Number' such that it becomes NOT NULL.
*/


CREATE PROCEDURE uspChangeColumnFansNumber AS
	ALTER TABLE Fans
	ALTER COLUMN Fans_Number INT NOT NULL
GO


CREATE PROCEDURE uspChangeBackColumnFansNumber AS
	ALTER TABLE Fans
	ALTER COLUMN Fans_Number INT
GO


/*
Version 8
Makes the Fans Name column into a candidate key
*/

CREATE PROCEDURE uspCreateCandidateKey AS
	ALTER TABLE Fans
	ADD CONSTRAINT UC_Fans UNIQUE (Fans_ID, Fans_Name);
GO


CREATE PROCEDURE uspDropCandidateKey AS
	ALTER TABLE Fans
	DROP CONSTRAINT UC_Fans;
GO


/* ```````````````````````````````````````` */

CREATE TABLE Procedures_versions
	(uspUp VARCHAR(50),
	uspDown VARCHAR(50),
	targetVersion INT
	)


INSERT INTO Procedures_versions
VALUES ('uspAddTableFans','uspDropTableFans',1),
		('uspChangeColumnFans_Name','uspBackChangeColumnFans_Name',2),
		('uspAddTableFanbase','uspDropTableFanbase',3),
		('uspAddFKtoFanbase','uspDropFKfromFanbase',4),
		('uspCreatePKforFanbase','uspDropPKforFanbase',5),
		('uspAddFKMaptoFanbase','uspDropFKMaptoFanbase',6),
		('uspChangeColumnFansNumber','uspChangeBackColumnFansNumber',7),
		('uspCreateCandidateKey','uspDropCandidateKey',8)

CREATE TABLE CrtVersion
	([version] INT)

INSERT CrtVersion([version])
VALUES (0)


/* Version 0 to 1 
Adds/deletes a 'fans' table, which is a table with fans from a particular point of the world. */
EXEC uspAddTableFans

/* Version 1 to 2 
Modifies the column 'Fans_Name' such that it becomes VARCHAR. */
EXEC uspChangeColumnFans_Name

/* Version 2 to 3
Adds/deletes a 'fanbase' table for a team, which is a separated table that contains a fanbase. */
EXEC uspAddTableFanbase

/* Version 3 to 4 
Adds/deletes foreigns keys team_ID (from Team) and fans_ID (from Fans) to the 'fanbase' table. */
EXEC uspAddFKtoFanbase

/* Version 4 to 5 
Creates/deletes a primary key to 'fanbase' table that is made out of team_ID and fans_ID. */
EXEC uspCreatePKforFanbase

/* Version 5 to 6 
Adds/deletes a foreign key to the 'fanbase' table, which is the map they enjoy watching the most (from Map: Map_ID) */
EXEC uspAddFKMaptoFanbase

/* Version 6 to 7 
Modifies the column 'Fans_Number' such that it becomes NOT NULL. */
EXEC uspChangeColumnFansNumber

/* Version 7 to 8
Creates a cadidate key to 'Fans' table that is made out of Fans_ID and Fans_Name. */
EXEC uspCreateCandidateKey

/* Version 8 to 7 */
EXEC uspDropCandidateKey

/* Version 7 to 6 */
EXEC uspChangeBackColumnFansNumber

/* Version 6 to 5 */
EXEC uspDropFKMaptoFanbase

/* Version 5 to 4 */
EXEC uspDropPKforFanbase

/* Version 4 to 3 */
EXEC uspDropFKfromFanbase

/* Version 3 to 2 */
EXEC uspDropTableFanbase

/* Version 2 to 1 */
EXEC uspBackChangeColumnFans_Name

/* Version 1 to 0 */
EXEC uspDropTableFans
