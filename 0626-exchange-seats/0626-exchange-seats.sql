# Write your MySQL query statement below
SELECT 
    CASE 
        WHEN ID % 2 = 1 AND ID+1 IN(SELECT ID FROM SEAT) THEN ID+1
        WHEN ID % 2 = 0 THEN ID - 1
        ELSE ID
        END ID, STUDENT
FROM SEAT
ORDER BY ID