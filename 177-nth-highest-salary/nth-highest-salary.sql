CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
    Select salary 
    from(
        Select salary, DENSE_RANK()
        OVER(ORDER BY salary DESC) as rnk
        from employee
    )e
    where e.rnk = N
    LIMIT 1
  );
END