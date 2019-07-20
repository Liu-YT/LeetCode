CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE tmp INT;
    set tmp = N-1;
    RETURN (
        # Write your MySQL query statement below.
        select distinct Salary
        from Employee order by Salary desc
        limit tmp, 1
    );
END