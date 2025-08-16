# Write your MySQL query statement below
SELECT p.product_name, SUM(o.unit) as unit
from Products p JOIN Orders o
    ON o.product_id = p.product_id
where (o.order_date BETWEEN '2020-02-01' AND '2020-02-29') 
GROUP BY p.product_name
HAVING SUM(o.unit) >= 100;