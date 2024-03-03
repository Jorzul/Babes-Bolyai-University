USE [CSGO Matches]
GO

CREATE TABLE Coach
	(Coach_ID INT PRIMARY KEY,
	Coach_Name VARCHAR(50),
	Coach_Win_Percentage INT CHECK(Coach_Win_Percentage >= 1 AND Coach_Win_Percentage <=100)
	)

CREATE TABLE Team
	(Team_ID INT PRIMARY KEY,
	Team_Name VARCHAR(50),
	World_Ranking INT,
	Coach_ID INT REFERENCES Coach(Coach_ID),
	Team_Rating INT
	)

CREATE TABLE Sponsor
	(Sponsor_ID INT PRIMARY KEY,
	Sponsor_Name VARCHAR(50),
	Sponsor_Origin VARCHAR(50),
	Sponsor_Budget INT)

CREATE TABLE Team_Sponsor
	(Team_ID INT REFERENCES Team(Team_ID),
	Sponsor_ID INT REFERENCES Sponsor(Sponsor_ID),
	PRIMARY KEY (Team_ID, Sponsor_ID))

CREATE TABLE Player
	(Player_ID INT PRIMARY KEY,
	Player_Name VARCHAR(50),
	Player_Rating INT,
	Player_Nationality VARCHAR(50),
	Team_ID INT REFERENCES Team(Team_ID)
	)

CREATE TABLE Transfers
	(Transfer_ID INT PRIMARY KEY,
	Transfer_Date VARCHAR(11),
	Player_ID INT REFERENCES Player(Player_ID)
	)

CREATE TABLE Transfer_details
	(Detail_ID INT PRIMARY KEY,
	Transfer_Amount INT,
	Transfer_Method VARCHAR(50),
	Transfer_Motive VARCHAR(50),
	Transfer_ID INT REFERENCES Transfers(Transfer_ID)
	)

CREATE TABLE Map
	(Map_ID INT PRIMARY KEY,
	Map_Name VARCHAR(50))

CREATE TABLE Player_favorite_map
	(Player_ID INT REFERENCES Player(Player_ID),
	Map_ID INT REFERENCES Map(Map_ID),
	PRIMARY KEY (Player_ID, Map_ID)
	)

CREATE TABLE Strategy
	(Strategy_ID INT PRIMARY KEY,
	Strategy_Description VARCHAR(100),
	Strategy_Success_Rate INT CHECK(Strategy_Success_Rate >= 1 AND Strategy_Success_Rate <= 100),
	Strategy_Map INT REFERENCES Map(Map_ID)
	/*
	O anumita tactica nu poate fi jucata pe mai multe harti, insa putem avea mai multe tactici intr-o singura mapa.
	Asta inseamna ca avem o relatie de 1 to many. 
	*/
	)

CREATE TABLE MatchBO1
	/* 
	Aici avem un meci care este Best of 1, ceea ce inseamna ca se joaca doar o singura harta, echipa ce va castiga harta, va castiga meciul.
	*/
	(Match_ID INT PRIMARY KEY,
	Team1_ID INT REFERENCES Team(Team_ID),
	Team2_ID INT REFERENCES Team(Team_ID),
	Map_ID INT REFERENCES Map(Map_ID),
	Match_Date VARCHAR(30),
	Match_MVP INT REFERENCES Player(Player_ID)
	)

CREATE TABLE MatchBO3
	/*
	Acest meci este Best of 3. Best of 3 inseamna ca se vor juca minim 2 harti, maxim 3 harti daca e nevoie.
	Prima echipa ce castiga 2 harti, castiga meciul.
	Prima data se joaca harta aleasa de prima echipa, apoi se joaca harta aleasa de a doua echipa. Daca e nevoie ()
	*/
	(Match_ID INT PRIMARY KEY,
	Team1_ID INT REFERENCES Team(Team_ID),
	Team2_ID INT REFERENCES Team(Team_ID),
	Chosen_Map_by_T1 INT REFERENCES Map(Map_ID),
	Chosen_Map_by_T2 INT REFERENCES Map(Map_ID),
	Decider_Map INT REFERENCES Map(Map_ID),
	Match_Date VARCHAR(50),
	Match_MVP INT REFERENCES Player(Player_ID)
	)

CREATE TABLE Compilation
	(Compilation_ID INT PRIMARY KEY,
	Compilation_Name VARCHAR(50))

CREATE TABLE Highlight
	(Highlight_ID INT PRIMARY KEY,
	Highlight_Player INT REFERENCES Player(Player_ID),
	Highlight_Match INT REFERENCES MatchBO1(Match_ID),
	Compilation INT REFERENCES Compilation(Compilation_ID)
	)



/*
DROP TABLE Highlight
DROP TABLE MatchBO1
DROP TABLE MatchBO3
DROP TABLE Compilation
DROP TABLE Strategy
DROP TABLE Player_favorite_map
DROP TABLE Map
DROP TABLE Transfer_details
DROP TABLE Transfers
DROP TABLE Player
DROP TABLE Team_Sponsor
DROP TABLE Sponsor
DROP TABLE Team
DROP TABLE Coach
*/