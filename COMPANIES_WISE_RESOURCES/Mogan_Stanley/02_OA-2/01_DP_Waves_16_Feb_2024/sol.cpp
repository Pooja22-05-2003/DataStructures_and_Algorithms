/*
Approach:
1. Question is asking for total number of ways to replace the all -1.
2. There are two types of waves can be formed.
3. First is  [up -> down -> up] // even dp[i-1][1]+dp[i-1][2].....dp[i-1][j-1].
   Second is [Down -> Up -> Down] // odd dp[i-1][j+1] + dp[i-1][j+2].....dp[i-1][m].
4. How can we do this with dynamic programming :- 

dp[............................................................................N]. 

dp[i] = best answer(total number of ways) to create type1-wave; till index “i”(1 to i) 

Final answer -> dp[n].

Last step to solve dp problem :- Make a formula. 

dp[i][j] = number of ways to create a type1 and type2 wave till index “i” such that the number at 
index “i” is assumed to be j. If b[i] = -1; or else you have to take the fixed number .


*/