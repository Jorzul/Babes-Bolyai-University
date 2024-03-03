USE [CSGO Matches]
GO

INSERT INTO Coach(Coach_ID, Coach_Name, Coach_Win_Percentage)
VALUES (1, 'Swani', 62),
	(2, 'B1ad3', 77),
	(3, 'Aleksib', 87),
	(4, 'groove', 70),
	(5, 'XTQZZZ', 81)

UPDATE Coach
SET Coach_Win_Percentage = Coach_Win_Percentage - 5
WHERE Coach_Win_Percentage > 70

INSERT INTO Team(Team_ID, Team_Name, World_Ranking, Coach_ID, Team_Rating)
VALUES (1, 'G2', 1, 1, 110),
		(2, 'Natus Vincere', 6, 2, 120),
		(3, 'Cloud9', 11, 4, 105),
		(4, 'Vitality', 3, 5, 113)

INSERT INTO Sponsor(Sponsor_ID, Sponsor_Name, Sponsor_Origin, Sponsor_Budget)
VALUES (1, 'DXRacer', 'Russian', 250000),
		(2, 'Logitech', 'Belgium', 500000),
		(3, 'GamEnergy', 'French', 85000),
		(4, 'Corsair', 'Russian', 115000),
		(5, 'Fiverr', 'American', 230000),
		(6, 'HyperX', 'German', 730000),
		(7, 'Kinguin', 'Russian', 65000)

INSERT INTO Team_Sponsor(Team_ID, Sponsor_ID)
VALUES (1, 6),
		(2, 2),
		(4, 3),
		(3, 2)


UPDATE Team
SET World_Ranking = 5
WHERE Team_Name = 'Natus Vincere' OR Team_ID = 2

INSERT INTO Player(Player_ID, Player_Name, Player_Rating, Player_Nationality, Team_ID)
VALUES (1, 'NiKo', 121, 'Bosnian', 1),
	(2, 'huNter-', 112, 'Bosnian', 1),
	(3, 'm0NESY', 118, 'Russian', 1),
	(4, 'HooXi', 87, 'Danish', 1),
	(5, 'jks', 105, 'Australian', 1),
	(6, 's1mple', 129, 'Russian', 2),
	(7, 'b1t', 110, 'Ukrainian', 2),
	(8, 'Aleksib', 98, 'Finnish', 2),
	(9, 'iM', 99, 'Romanian', 2),
	(10, 'jL', 103, 'Lithuanian', 2),
	(11, 'HObbit', 108, 'Kazakhstanian', 3),
	(12, 'Ax1Le', 116, 'Russian', 3),
	(13, 'electroNic', 107, 'Russian', 3),
	(14, 'Perfecto', 108, 'Russian', 3),
	(15, 'sh1ro', 124, 'Russian', 3),
	(16, 'apEX', 101, 'French', 4),
	(17, 'ZywOo', 130, 'French', 4),
	(18, 'Magisk', 109, 'Danish', 4),
	(19, 'Spinx', 112, 'Israeli', 4),
	(20, 'flameZ', 109, 'Israeli', 4)

INSERT INTO Transfers(Transfer_ID, Transfer_Date, Player_ID)
VALUES (1, '03/11/2023', 18)

INSERT INTO Transfer_details(Detail_ID, Transfer_Amount, Transfer_Method, Transfer_Motive, Transfer_ID)
VALUES (1, 0, 'Out', 'No longer active in startup', 1)

UPDATE Player
SET Player_Rating = 113
WHERE Player_Name = 'iM' AND Player_Nationality = 'Romanian'

UPDATE Player
SET Player_Nationality = 'Ukrainian'
WHERE Player_ID = 6	

INSERT INTO Map(Map_ID, Map_Name)
VALUES (1, 'Inferno'),
	(2, 'Mirage'),
	(3, 'Dust_2'),
	(4, 'Nuke'),
	(5, 'Overpass'),
	(6, 'Ancient'),
	(7, 'Anubis')

INSERT INTO Player_favorite_map(Player_ID, Map_ID)
VALUES (1, 4),
	(1, 6),
	(3, 4),
	(6, 2),
	(11, 6)

INSERT INTO Strategy(Strategy_ID, Strategy_Description, Strategy_Success_Rate, Strategy_Map)
VALUES (1, 'A Full smokes: 1-CT, 1-Stairs, 1-Jungle', 81, 2),
	(2, 'B Flash Assist: Banana Pop-Flash', 50, 1),
	(3, 'B Full smokes: 1-CT, 1-Graveyard', 50, 1),
	(4, 'A Flash Assist: Short Pop-Flash while terrorist', 41, 3),
	(5, 'B Full smokes: 1-Market, 1-Short, 1-Bench', 77, 2)

INSERT INTO MatchBO1(Match_ID, Team1_ID, Team2_ID, Map_ID, Match_Date, Match_MVP)
VALUES (1, 1, 2, 5, '23/06/2023', 6)

INSERT INTO Compilation(Compilation_ID, Compilation_Name)
VALUES (1, 's1mple 1v3')

INSERT INTO Highlight(Highlight_ID, Highlight_Player, Highlight_Match, Compilation)
VALUES (1, 6, 1, 1)

/*
DELETE FROM Highlight
DELETE FROM MatchBO1 WHERE Match_ID > 0
DELETE FROM Player_favorite_map
DELETE FROM Strategy
DELETE FROM Map WHERE Map_ID > 0
DELETE FROM Transfer_details
DELETE FROM Transfers
DELETE FROM Compilation
DELETE FROM Player WHERE Player_ID IS NOT NULL
DELETE FROM Team_Sponsor
DELETE FROM Sponsor
DELETE FROM Team WHERE Team_ID > 0
DELETE FROM Coach WHERE Coach_ID = 1 OR Coach_ID > 1
*/

SELECT * FROM Player
SELECT * FROM Team
SELECT * FROM Sponsor
SELECT * FROM Team_Sponsor
SELECT * FROM Map
SELECT * FROM Player_favorite_map
SELECT * FROM Strategy
SELECT * FROM MatchBO1
SELECT * FROM Coach
SELECT * FROM Transfers
SELECT * FROM Transfer_details
SELECT * FROM Compilation
SELECT * FROM Highlight
