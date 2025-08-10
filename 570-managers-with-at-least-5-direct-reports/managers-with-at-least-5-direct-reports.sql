# Write your MySQL query statement below
SELECT e.name from Employee e 
JOIN(
    SELECT managerId from Employee
    where managerId is not NULL
    group by managerId 
    having COUNT(*) >= 5
) valid
on e.id = valid.managerId;