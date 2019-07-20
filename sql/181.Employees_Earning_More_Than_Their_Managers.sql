select a.Name as Employee
from employee a, employee b
where a.ManagerId = b.Id && a.Salary > b.Salary