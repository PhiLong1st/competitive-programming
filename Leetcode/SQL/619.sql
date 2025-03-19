/* Write your T-SQL query statement below */
Declare @num int = null

Select Top 1 @num = 
    num 
From MyNumbers
Group By num 
Having Count(num) = 1
Order By num DESC

SELECT @num AS num