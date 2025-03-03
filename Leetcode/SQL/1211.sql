-- https://leetcode.com/problems/queries-quality-and-percentage/description/
SELECT 
    a.query_name, 
    ROUND(SUM(a.rating * 1.0 / a.position) / COUNT(a.query_name), 2) AS quality, 
    ROUND(SUM(CASE WHEN a.rating < 3 THEN 1 ELSE 0 END) * 100.0 / COUNT(a.query_name), 2) AS poor_query_percentage
FROM Queries a
GROUP BY a.query_name;
