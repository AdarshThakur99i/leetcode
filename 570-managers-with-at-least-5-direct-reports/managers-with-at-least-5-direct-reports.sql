# Write your MySQL query statement below
SELECT  p.name 
FROM Employee AS m
JOIN Employee AS P
ON m.managerId=p.id
GROUP BY p.id,p.name
HAVING COUNT(m.id)>=5;

