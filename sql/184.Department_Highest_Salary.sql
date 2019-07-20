# Write your MySQL query statement below
select S.departmentName as "Department", S.name as "Employee", S.salary as "Salary"
from (select E.name, E.salary, E.departmentid, D.name as departmentName
    from employee E inner join Department D on E.departmentid=D.id) as S
    inner join (select departmentid, max(salary) as m
    from employee
    group by departmentid) as T
    on T.departmentid = S.departmentid
where T.m = S.salary;