# Write your MySQL query statement below
SELECT p.product_id,
    ROUND(IFNULL(SUM(us.units * p.price) / SUM(us.units), 0), 2)
    as average_price
from Prices p
LEFT JOIN UnitsSold us
    on p.product_id = us.product_id
    AND us.purchase_date BETWEEN p.start_date AND p.end_date
group by p.product_id;