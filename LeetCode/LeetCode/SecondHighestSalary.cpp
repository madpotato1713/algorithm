/* NOT IN: */
SELECT MAX(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary NOT IN(SELECT MAX(Salary) FROM Employee);

/* The < Operator: */
SELECT MAX(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT MAX(Salary) FROM Employee);

/* LIMIT and OFFSET: */
SELECT(SELECT DISTINCT Salary
	FROM Employee
	ORDER BY Salary DESC LIMIT 1 OFFSET 1) AS SecondHighestSalary;