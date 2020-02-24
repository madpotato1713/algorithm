# Write your MySQL query statement below
SELECT ps.FirstName, ps.LastName, ad.City, ad.State
FROM Person AS ps
LEFT JOIN Address AS ad
ON ps.PersonId = ad.PersonId;