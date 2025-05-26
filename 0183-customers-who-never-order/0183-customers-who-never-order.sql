# Write your MySQL query statement below
SELECT Customers.name AS Customers
FROM CUSTOMERS
LEFT JOIN ORDERS ON CUSTOMERS.id = ORDERS.customerId
WHERE ORDERS.customerId IS NULL;
