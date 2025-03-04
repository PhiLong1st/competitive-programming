-- https://leetcode.com/problems/game-play-analysis-iv/description/
SELECT 
    ROUND(
        (COUNT(DISTINCT a1.player_id) * 1.0) / 
        (
            SELECT COUNT(DISTINCT player_id)
            FROM Activity
        ), 
        2
    ) AS fraction
FROM 
    (
        SELECT 
            player_id, 
            MIN(event_date) AS event_date
        FROM 
            Activity
        GROUP BY 
            player_id
    ) a1
INNER JOIN 
    Activity a2 
    ON a1.player_id = a2.player_id
WHERE 
    DATEDIFF(day, a1.event_date, a2.event_date) = 1;
