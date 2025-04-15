# Write your MySQL query statement below
SELECT NAME, BONUS
FROM EMPLOYEE E
LEFT JOIN BONUS B ON E.EMPID = B.EMPID
WHERE BONUS IS NULL OR BONUS <1000