-- Link:  https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/description/
/* Write your T-SQL query statement below */
Select a.employee_id, a.name, b.reports_count, b.average_age  
From Employees a 
Right Join
(Select reports_to As id, Round(Avg(1.0 * age), 0) As average_age, Count(reports_to) As reports_count
From Employees
Where reports_to Is Not Null
Group By reports_to) As b
On a.employee_id = b.id