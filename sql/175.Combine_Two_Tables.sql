/* solution 1 */
select p.FirstName, p.LastName, a.City, a.State 
from person p left join address a on p.PersonId = a.PersonId;

/* solution 2 */
select FirstName, LastName, City, State
from person left join address on person.PersonId = address.PersonId;