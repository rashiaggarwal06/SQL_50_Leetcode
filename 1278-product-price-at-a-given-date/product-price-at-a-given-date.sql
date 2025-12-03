# Write your MySQL query statement below
Select
    product_id,
    IFNULL((Select new_price from Products 
        where product_id = p.product_id and change_date <= '2019-08-16'
        order by change_date desc
        limit 1), 10) AS price
from Products p
group by product_id;