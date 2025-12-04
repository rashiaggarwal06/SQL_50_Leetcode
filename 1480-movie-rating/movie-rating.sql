# Write your MySQL query statement below
(
    Select name as results
    from Users u
    join MovieRating mr on u.user_id = mr.user_id
    group by u.user_id
    order by COUNT(*) desc, name
    limit 1
)
union all
(
    Select title AS results
    from Movies m
    join MovieRating mr on m.movie_id = mr.movie_id
    where mr.created_at between '2020-02-01' and '2020-02-29'
    group by m.movie_id
    order by AVG(mr.rating) DESC, title
    limit 1
);
