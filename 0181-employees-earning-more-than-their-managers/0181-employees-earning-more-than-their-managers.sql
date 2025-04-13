# Write your MySQL query statement below
SELECT E2.name AS Employee
FROM Employee E1
INNER JOIN Employee E2 ON E1.ID = E2.MANAGERID
WHERE E1.SALARY < E2.SALARY

