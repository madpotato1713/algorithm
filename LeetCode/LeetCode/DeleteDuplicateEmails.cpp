/* CASE1 */
# Write your MySQL query statement below
DELETE P1 FROM Person AS P1, Person AS P2 WHERE P1.Id > P2.Id AND P1.Email = P2.Email;

/* CASE2 */
DELETE p1
FROM Person AS p1
WHERE EXISTS(
	SELECT 1
	FROM(SELECT * FROM Person) AS p2
	WHERE p1.Email = p2.Email
	AND p2.Id < p1.Id
);