# Write your MySQL query statement below
with first_order as(
    Select d.*
    from Delivery d
    join(
        Select customer_id, min(order_date) as first_date
        from Delivery
        group by customer_id
    ) f
    on d.customer_id = f.customer_id 
    and d.order_date = f.first_date
)
Select 
    Round(avg(case when order_date = customer_pref_delivery_date then 1.0 else 0 end) * 100, 2) AS immediate_percentage
FROM first_order;