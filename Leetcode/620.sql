-- Link: https://leetcode.com/problems/not-boring-movies/
Select * from Cinema 
Where Cinema.description <> 'boring' And Cinema.id % 2 = 1
Order by Cinema.rating Desc