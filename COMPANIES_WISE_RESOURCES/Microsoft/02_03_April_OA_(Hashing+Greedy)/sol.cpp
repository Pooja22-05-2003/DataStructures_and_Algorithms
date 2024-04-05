/*

How will you make the first row balanced and make them have an equal number of R and W. 

Replace the “?” with R and the first row is balanced.

How will you balance the second row ? 

R   R  W  W 
W W  R   R 

This is balanced because each row and column has an equal number of R and W. 
Let's try to make only the rows equal then what will be the algorithm to make any row equal ? 


Count the number of “R” in row and count the number of “W” ; whichever is bigger try to make the smaller character frequency equal to the bigger one by replacing the “?”. 

This will make sure the job gets done in minimum operations. 

If you are not able to do it print -1 ok 


*/


