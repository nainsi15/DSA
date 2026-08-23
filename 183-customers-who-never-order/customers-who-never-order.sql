# Write your MySQL query statement below
SELECT name as Customers
FROM CUSTOMERs
LEFT JOIN orders
ON customers.id = orders.customerId
where orders.customerid is null