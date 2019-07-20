/* solution 1 */
select Name as Customers
from Customers
where Id not in (select CustomerId from Orders)


/* solution 2 */
select Customers.Name as Customers
from Customers left join Orders on Customers.Id = Orders.CustomerId
where CustomerId is NULL