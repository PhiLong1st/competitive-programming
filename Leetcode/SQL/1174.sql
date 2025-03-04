-- https://leetcode.com/problems/immediate-food-delivery-ii/description/
SELECT 
    ROUND(
        SUM(CASE WHEN b.order_date = d.customer_pref_delivery_date THEN 1 ELSE 0 END) * 100.0 / 
        COUNT(DISTINCT d.customer_id), 2
    ) AS immediate_percentage
FROM 
    Delivery d
RIGHT JOIN 
    (
        SELECT 
            customer_id, 
            MIN(order_date) AS order_date
        FROM 
            Delivery
        GROUP BY 
            customer_id
    ) AS b
ON 
    d.customer_id = b.customer_id;
