# Write your MySQL query statement below
SELECT(
SELECT MyNumbers.num as num
FROM MyNumbers
GROUP BY num
HAVING COUNT(*)=1
ORDER BY num DESC 
LIMIT 1
) AS num;