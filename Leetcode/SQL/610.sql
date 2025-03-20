-- Link: https://leetcode.com/problems/triangle-judgement/description/
/* Write your T-SQL query statement below */
Select *, CASE
    WHEN t.x + t.y > t.z And t.x + t.z > t.y And t.z + t.y > t.x 
    THEN 'Yes'
    ELSE 'No'
END AS triangle 
From Triangle t