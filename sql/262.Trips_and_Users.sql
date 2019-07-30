select allo.r as Day, round(ifnull(canceled.c/allo.c,0),2) as `Cancellation Rate`
from
    (select count(1) as c, Request_at as r
    from Trips t, Users u
    where t.Client_Id = u.Users_Id and u.Banned = 'No' and t.Request_at between '2013-10-01' and '2013-10-03' and t.Status != 'completed'
    group by Request_at)  as canceled
    right join
    (select count(1) as c, Request_at as r
    from Trips t, Users u
    where t.Client_Id = u.Users_Id and u.Banned = 'No' and t.Request_at between '2013-10-01' and '2013-10-03'
    group by Request_at) as allo
    on canceled.r = allo.r 