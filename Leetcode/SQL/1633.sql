-- https://leetcode.com/problems/percentage-of-users-attended-a-contest/description/

DECLARE @user FLOAT = 100.0 / (SELECT count(user_id) FROM Users)
SELECT 
    contest_id, 
    ROUND(COUNT(Distinct user_id) * @user, 2) AS percentage
FROM 
    Register AS r
GROUP BY 
    contest_id
ORDER BY 
    percentage DESC, contest_id ASC;