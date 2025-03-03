-- https://leetcode.com/problems/monthly-transactions-i/description/
Select format(t.trans_date, 'yyyy-MM') AS month, t.country, 
Count(*) As trans_count,
Sum(Case When t.state = 'approved' Then 1 Else 0 End) as approved_count, 
Sum(t.amount) as trans_total_amount,
Sum(Case When t.state = 'approved' Then t.amount Else 0 End) as approved_total_amount
FROM Transactions t
GROUP BY format(t.trans_date, 'yyyy-MM'), t.country;
