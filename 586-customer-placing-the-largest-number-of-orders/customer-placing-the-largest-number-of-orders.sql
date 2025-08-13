# Write your MySQL query statement below
SELECT Orders.customer_number
FROM Orders
GROUP BY Orders.customer_number
ORDER BY COUNT(*) DESC
LIMIT 1;

