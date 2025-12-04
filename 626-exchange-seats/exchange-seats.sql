# Write your MySQL query statement below
Select id,
    case 
        when MOD(id, 2) = 1 and id < (Select MAX(id) from Seat) then 
            (Select student from Seat where id = s.id + 1)
        when MOD(id, 2) = 0 then 
            (Select student from Seat where id = s.id - 1)
        else student
    end as student
from Seat s
order by id;