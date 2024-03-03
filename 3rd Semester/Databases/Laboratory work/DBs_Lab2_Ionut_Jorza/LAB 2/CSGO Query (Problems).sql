USE [CSGO Matches]
GO


/* A */
/* Select all the players and the coaches. */
SELECT Player_Name FROM Player
UNION
SELECT Coach_Name FROM Coach
ORDER BY Player_Name

/* Select all the ratings and win percentages of the players and the coaches. */
SELECT Player_Rating FROM Player
UNION ALL
SELECT Coach_Win_Percentage FROM Coach
ORDER BY Player_Rating DESC



/* B */
/* Select all the players that are coaches aswell. */
SELECT Player_Name FROM Player
INTERSECT
SELECT Coach_Name FROM Coach

/* Select all the players that are either Russian or Ukrainian. */
SELECT Player_Name, Player_Nationality, Player_Rating FROM Player
WHERE Player_Nationality IN ('Russian', 'Ukrainian')
ORDER BY Player_Rating DESC



/* C */
/* Select only those coaches that do not play at the moment. */
SELECT Coach_Name FROM Coach
EXCEPT
SELECT Player_Name FROM Player

/* Select the players that are not Russian nor Ukrainian. */
SELECT * FROM Player
WHERE Player_Nationality NOT IN ('Russian', 'Ukrainian')
ORDER BY Player_Name



/* D */
/* Select all the transfers for every player (with motive and date aswell). */
SELECT 
	Player.Player_ID, Player.Player_Name,
	Transfers.Transfer_ID, Transfers.Transfer_Date,
	Transfer_details.Detail_ID, Transfer_details.Transfer_Motive
FROM
	Player
INNER JOIN Transfers
	ON Player.Player_ID = Transfers.Transfer_ID
INNER JOIN Transfer_details
	ON Transfers.Transfer_ID = Transfer_details.Detail_ID


/* Select all the coaches that have played for a team which played in atleast one game. */
SELECT 
	Coach.Coach_ID, Coach.Coach_Name,
	Team.Team_ID, Team.Team_Name,
	MatchBO1.Match_ID
FROM 
	Coach
RIGHT JOIN Team
	ON Coach.Coach_ID = Team.Team_ID
RIGHT JOIN MatchBO1
	ON Team.Team_ID = MatchBO1.Match_ID


/* Select all the players, showing which matches they played in. */
SELECT
	Player.Player_ID, Player.Player_Name,
	Team.Team_ID, Team.Team_Name,
	MatchBO1.Match_ID
FROM
	Player
LEFT JOIN Team
	ON Player.Team_ID = Team.Team_ID
LEFT JOIN MatchBO1
	ON Team.Team_ID = MatchBO1.Team1_ID OR Team.Team_ID = MatchBO1.Team2_ID


/* Select all the players, showing which maps they enjoy the most to play. */
SELECT
	Player.Player_ID, Player.Player_Name,
	Map.Map_ID, Map.Map_Name
FROM 
	Player
FULL JOIN Player_favorite_map
	ON Player.Player_ID = Player_favorite_map.Player_ID
FULL JOIN Map
	ON Player_favorite_map.Map_ID = Map.Map_ID



/* E */
/* Select all the teams that have a coach with a win percentage of more than 70% */
SELECT
	Team_ID,
	Team_Name,
	World_Ranking
FROM
	Team
WHERE Coach_ID IN (
					SELECT Coach_ID
					FROM Coach
					WHERE Coach_Win_Percentage > 70)


/* Select all the players that play in a team with a rating bigger than 1.4* the best win percentage of coaches. */
SELECT
	Player_ID,
	Player_Name,
	Player_Rating
FROM
	Player
WHERE Team_ID IN (
					SELECT TEAM_ID
					FROM Team
					WHERE Team_Rating > 1.4 * (
												SELECT MAX(Coach_Win_Percentage)
												FROM Coach
												)
				)



/* F */
/* Select all the players that play for a team with a rating of more than 110. */
SELECT
	Player_ID,
	Player_Name,
	Team_ID
FROM
	Player p
WHERE
	EXISTS (
		SELECT 1
		FROM Team t
		WHERE p.Team_ID = t.Team_ID
		AND t.Team_Rating > 110)


/* Select all the strategies that can be played on Inferno. */
SELECT
	Strategy_ID,
	Strategy_Description,
	Strategy_Success_Rate
FROM
	Strategy s
WHERE
	EXISTS (
		SELECT 1
		FROM Map m
		WHERE s.Strategy_Map = m.Map_ID
		AND m.Map_Name = 'Inferno')


/* G */
/* Select all the russian players that have a rating of more than 115. */
SELECT sub.*
FROM (
	SELECT *
		FROM Player
		WHERE Player_Nationality = 'Russian'
	) sub
WHERE sub.Player_Rating > 115


/* Select all the players that have a rating of more than 1.5* the biggest win percentage of all the coaches. */
SELECT *
FROM Player
WHERE Player_Rating > 1.5* (SELECT MAX(Coach_Win_Percentage)
						FROM Coach						
						)



/* H */
/* Count how many nationalities are there among all the players. */
SELECT Count(Player_ID), Player_Nationality
FROM Player
GROUP BY Player_Nationality


/* Select and group all the players with a rating of more than 110. */
SELECT Player_Name, Player_Rating
FROM Player
GROUP BY Player_Rating, Player_Name
HAVING Player_Rating > 110


/* Select and group all the players that averages a rating bigger than the average rating of all teams. */
SELECT Player_Name, AVG(Player_Rating)
FROM Player
GROUP BY Player_Name
HAVING AVG(Player_Rating) > (
							SELECT AVG(Team_Rating)
							FROM Team
							)


/* Select all the coaches that averages a win percentage bigger than the average rating of all russian players. */
SELECT Coach_Win_Percentage
FROM Coach
GROUP BY Coach_Win_Percentage
HAVING AVG(Coach_Win_Percentage) * 1.65 > (
										SELECT AVG(Player_Rating)
										FROM Player
										WHERE Player_Nationality = 'Russian'
										)



/* I */
/* Select all the coaches that currently play for a team. */
SELECT *
FROM Coach
WHERE Coach_ID = ANY (
					SELECT Coach_ID FROM Team)



/* Select all the matches where s1mple was the MVP. */
SELECT *
FROM MatchBO1
WHERE Match_MVP IN (
					SELECT Player_ID FROM Player
					WHERE Player_Name = 's1mple')



/* Select all the players that play for a team in the top 3. */
SELECT *
FROM Player
WHERE Team_ID NOT IN (
					SELECT Team_ID FROM Team
					WHERE World_Ranking > 3)
