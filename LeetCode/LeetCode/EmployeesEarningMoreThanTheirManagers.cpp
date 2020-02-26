# Write your MySQL query statement below

# SELECT Name FROM Employee
# WHERE ManagerId IS NOT NULL
# AND Salary > (
	#     SELECT Salary WHERE
# )

	SELECT A.Name AS Employee
	FROM Employee AS A, Employee AS B
	WHERE A.ManagerId = B.Id
	AND A.Salary > B.Salary
	;