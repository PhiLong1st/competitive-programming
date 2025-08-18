/* Write your T-SQL query statement below */
Declare @cnt int;

Select @cnt = Count(product_key) 
From Product 

Select customer_id 
From Customer 
Group By customer_id 
Having Count(distinct product_key) = @cnt