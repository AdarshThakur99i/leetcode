# Write your MySQL query statement below

SELECT name 
FROM SalesPerson
WHERE SalesPerson.sales_id NOT IN
  (SELECT sales_id FROM Orders
  WHERE Orders.com_id IN (
    SELECT com_id FROM Company
    WHERE Company.name="RED"
  ))
