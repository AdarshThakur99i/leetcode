# Write your MySQL query statement below
SELECT c.name 
FROM Customer as c
LEFT JOIN Customer as m
ON c.referee_id=m.id
WHERE m.id !=2 OR m.id IS NULL