# Write your MySQL query statement below

SELECT customer_id,count(v.visit_id) as count_no_trans
FROM Visits as v
LEFT JOIN   Transactions
ON (v.visit_id) = (Transactions.visit_id) 
WHERE Transactions.transaction_id IS NULL
GROUP BY customer_id;
