-- Link: https://leetcode.com/problems/average-selling-price/
SELECT tb.product_id, 
       COALESCE(ROUND(CAST(tb.a AS FLOAT) / NULLIF(CAST(tb.b AS FLOAT), 0), 2), 0) AS average_price
FROM (
    SELECT t.product_id, 
           SUM(t.total_price) AS a, 
           SUM(t.total_unit) AS b 
    FROM (
        SELECT p.product_id, 
               SUM(u.units * p.price) AS total_price, 
               SUM(u.units) AS total_unit
        FROM Prices AS p 
        LEFT JOIN UnitsSold AS u 
            ON p.product_id = u.product_id 
            AND u.purchase_date BETWEEN p.start_date AND p.end_date
        GROUP BY p.product_id
    ) AS t
    GROUP BY t.product_id
) AS tb;
