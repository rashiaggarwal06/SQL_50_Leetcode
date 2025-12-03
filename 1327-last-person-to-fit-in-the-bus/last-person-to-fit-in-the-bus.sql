# Write your MySQL query statement below
Select person_name
from(
    Select person_name, SUM(weight) over(order by turn) as w
    from Queue
) t
where w <= 1000
order by w desc
limit 1;