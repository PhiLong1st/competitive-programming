/*
    Code by: KoKoDuDu
    Link: https://leetcode.com/problems/confirmation-rate/description/
*/
-- MS SQL
SELECT tb_b.user_id,
       COALESCE(ROUND(CONVERT(FLOAT, tb_a.confirmation) / NULLIF(CONVERT(FLOAT, tb_b.confirmation_cnt), 0), 2), 0) AS confirmation_rate
FROM
  (SELECT cf.user_id,
          COUNT(*) AS confirmation
   FROM Confirmations AS cf
   WHERE cf.action = 'confirmed'
   GROUP BY cf.user_id) AS tb_a
RIGHT JOIN
  (SELECT s.user_id,
          COUNT(cf.action) AS confirmation_cnt
   FROM Signups AS s
   LEFT JOIN Confirmations AS cf ON s.user_id = cf.user_id
   GROUP BY s.user_id) AS tb_b ON tb_a.user_id = tb_b.user_id;