# Write your MySQL query statement below
SELECT x,y,z,
CASE 
 WHEN ABS(x)+ABS(y) <= ABS(z) OR ABS(y)+ABS(z) <= ABS(x) OR ABS(x)+ABS(z) <= ABS(y) THEN "No"

 ELSE "Yes"
 END AS triangle
 FROM Triangle;