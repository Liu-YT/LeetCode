/* solution 1 */
select Max(salary) as SecondHighestSalary
from Employee
where salary not in (
    select Max(salary)
    from Employee
)

/* solution 2 */
select Max(salary) as SecondHighestSalary
from Employee
where salary < (
    select Max(salary)
    from Employee
)

/* solution 3 */
select (
    select distinct  salary
    from Employee order by salary desc
    limit 1 offset 1
)  as SecondHighestSalary


/* 
知识补充 
1. as 其别名，可以省略，为了可读性建议加上 
2. limit x offset y 偏移y取x个数据
*/