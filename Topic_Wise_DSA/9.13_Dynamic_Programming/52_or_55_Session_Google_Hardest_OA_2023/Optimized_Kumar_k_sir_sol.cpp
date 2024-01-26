// Ideone Link : https://ideone.com/s4NKUB
->n.
->b[n+1]
->dp[n+5][n+5]


dp[i][j] => maximum sum of subsequence which has only j elements in it
from index 1 to i 

i=1
while(i<=n){
    
    j=1;
    while(j<=i){
        l = 1 
        while(l<=i-1){
            if(b[l]<=b[i]){
                 dp[i][j] = b[i] + dp[l][j-1] 
            }
            l=l+
        }
    }
    i++;
}
d = int_max; 
for(i=1;i<=n;i++){
    
    for(j=1;j<=i;j++){
        
        if(dp[i][j]>=k){
            
            d = min(d,j) 
            
        }
        
    }
    
    
}
r = d 
print(r)







