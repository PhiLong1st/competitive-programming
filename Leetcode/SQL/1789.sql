-- Link: https://leetcode.com/problems/primary-department-for-each-employee/description/
select employee_id, max(department_id) [department_id]
from employee
group by employee_id
having count(department_id) = 1

union

select employee_id, department_id [department_id]
from employee
where primary_flag = 'Y'
group by employee_id, department_id