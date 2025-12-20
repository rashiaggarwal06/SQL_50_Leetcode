# Write your MySQL query statement below
Select round(sum(tiv_2016), 2) AS tiv_2016
from Insurance
where tiv_2015 in(
    Select tiv_2015 from Insurance group by tiv_2015 having COUNT(*) > 1)
and(lat, lon) in(
    Select lat, lon from Insurance group by lat, lon having COUNT(*) = 1);