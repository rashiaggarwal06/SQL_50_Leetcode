# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT v.customer_id, COUNT(*) AS count_no_trans
from Visits v 
LEFT JOIN transactions t
    on v.visit_id = t.visit_id
where t.transaction_id is NULL
group by v.customer_id;