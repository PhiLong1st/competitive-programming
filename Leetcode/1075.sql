-- https://leetcode.com/problems/project-employees-i/description/
-- Sol 1
Select p.project_id, Coalesce(Round(Convert(Decimal, Sum(e.experience_years)) / Convert(Decimal, Count(p.project_id)), 2), 0) As average_years 
From Project As p Left Join Employee As e
On p.employee_id = e.employee_id   
Group By p.project_id;
-- Sol 2
Select p.project_id, Round(Avg(Convert(Decimal, e.experience_years)), 2) As average_years 
From Project As p Left Join Employee As e
On p.employee_id = e.employee_id   
Group By p.project_id;