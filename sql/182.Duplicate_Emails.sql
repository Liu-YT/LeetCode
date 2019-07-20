/* solution 1 */
select distinct p1.Email
from Person p1, Person p2
where p1.Email = p2.Email && p1.Id != p2.Id


/* solution 2 */
select Email
from Person 
group by Email
having count(Email) > 1;