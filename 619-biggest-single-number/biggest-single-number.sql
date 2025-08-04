# Write your MySQL query statement below
SELECT max(num) AS num
from(
  SELECT num
  from MyNumbers
  Group by num
  Having count(*) = 1
) AS UniqueNums;