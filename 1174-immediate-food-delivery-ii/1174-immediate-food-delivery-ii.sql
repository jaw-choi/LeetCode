# Write your MySQL query statement below
SELECT ROUND(AVG(ORDER_DATE = CUSTOMER_PREF_DELIVERY_DATE)*100,2) AS IMMEDIATE_PERCENTAGE
FROM DELIVERY
WHERE (CUSTOMER_ID,ORDER_DATE)IN(
    SELECT CUSTOMER_ID, MIN(ORDER_DATE)
    FROM DELIVERY
    GROUP BY CUSTOMER_ID
)