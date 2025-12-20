# Write your MySQL query statement below
Select d.name AS Department, e.name AS Employee, e.salary AS Salary
from Employee e
join Department d
  on e.departmentId = d.id
where(
    Select count(distinct e2.salary)
    from Employee e2
    where e2.departmentId = e.departmentId
      and e2.salary > e.salary
) < 3;