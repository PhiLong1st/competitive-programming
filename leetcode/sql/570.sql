/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/managers-with-at-least-5-direct-reports/
*/
-- MS SQL
SELECT e.name 
FROM (
    SELECT managerId, COUNT(managerId) AS emp_count 
    FROM Employee 
    WHERE managerId IS NOT NULL  
    GROUP BY managerId
) AS a
JOIN Employee AS e
ON e.id = a.managerId and a.emp_count >= 5;
