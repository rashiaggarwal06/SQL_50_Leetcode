# Write your MySQL query statement below
Select c1.visited_on,
    sum(c2.amount) AS amount,
    round(sum(c2.amount) / 7, 2) AS average_amount
from (select visited_on, SUM(amount) AS amount
     from Customer
     group by visited_on) c1
join (select visited_on, SUM(amount) AS amount
     from Customer
     group by visited_on) c2
on c2.visited_on between DATE_SUB(c1.visited_on, INTERVAL 6 DAY) and c1.visited_on
group by c1.visited_on
having COUNT(distinct c2.visited_on) = 7
order by c1.visited_on;