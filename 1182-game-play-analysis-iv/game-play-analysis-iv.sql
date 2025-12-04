# Write your MySQL query statement below
with first_login as(
    Select player_id, MIN(event_date) as first_day
    from Activity
    group by player_id
)
Select 
    Round(Count(a.player_id) / (Select COUNT(*) from first_login), 2) as fraction
from first_login f
left join Activity a
    on f.player_id = a.player_id
    and a.event_date = DATE_ADD(f.first_day, INTERVAL 1 DAY);