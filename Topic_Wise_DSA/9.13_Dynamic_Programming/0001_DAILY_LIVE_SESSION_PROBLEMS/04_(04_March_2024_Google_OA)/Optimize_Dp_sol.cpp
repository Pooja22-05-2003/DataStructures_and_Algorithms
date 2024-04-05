// O(N*3K) = O(N*K) 

// ->b[n+1]->1-based indexing 

// dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = .....dp[1][b[1]] = 0 
// special[1][1] = ....................... = special[1][b[1]] = 0 
// suffix[1][1] ============================ 0
// special26[][]

// for(int i=2;i<=n;i++){ //O(N)
//      for(int j=1;j<=b[i];j++){ //O(G)
//     //   for(second_last_value = 1;second_last_value<=b[i]-1;second_last_value++)
//     //   {   //1-----7
//     //       G = abs(second_last_value-j) + dp[i-1][second_last_value]
//     //       Dp[i][j] = max(dp[i][j],G) 
//     //   }
       
//        r5 = prefix[i-1][b[i]-1] = max(special26[i-1][1],special26[i-1][2],....special26[i-1][b[i]-1])
       
//     //   r = 0 
//     //   for(second_last_value = b[i];second_last_value<=b[i-1];second_last_value++){
//     //       //8----100
//     //       u = special[i-1][j]
//     //       r = max(r,u)
//     //   }
//     r = suffix[i-1][j] = max(special[i-1][j],special[i-1][j+1],......special[i-1][b[i-1]])
       
//        dp[i][j] = max(dp[i][j],r-j,r5+j)
       
       
//        special[i][j] = dp[i][j]  + j 
//        special26[i][j] = dp[i][j] - j 
//      }
     
//      j = b[i]; //O(G)
//      while(j>=1){
//          suffix[i][j] = max(suffix[i][j+1],special[i][j])
//          j=j-1;
//      }
     
//      j = 1 //O(G)
//      while(j<=b[i]){
//          prefix[i][j] = max(prefix[i][j-1],special26[i][j])
//          j++;
//      }
    
// }

 


