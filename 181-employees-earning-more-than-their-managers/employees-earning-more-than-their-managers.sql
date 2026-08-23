# Write your MySQL query statement below
select  e.name as Employee
from EMPLOYEE e
JOIN EMPLOYEE m
ON e.managerID = m.id
AND e.salary > m.salary