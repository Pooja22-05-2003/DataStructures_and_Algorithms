#include <bits/stdc++.h>

using namespace std;
int dp[1005][1005];

int main() {
    
    int n,k ; cin>>n ;  
    cin>>k;
    int b[n+1] = {0};
    
    int i = 1 ;
    while(i<=n){
        cin>>b[i];
        i++;
    }
    
    int check[25]= {0};
    
    dp[1][1] = b[1] ; 
    int OR = b[1] ; 
    
    for (int i = 18; i >= 0; i--) {
    int k = b[1] >> i; 
    if (k & 1) {
        check[i] = 1 ; 
    } 
    else{
     //   cout << "0"; 
    }
    }    
    
    
    
    i = 2 ; 
    while(i<=n){
        
        dp[i][1] = (OR | b[i]);
        int OO[n+5]={0};
        
        //pre-calculation of all SUFFIX OR 
        
        int ii = i ; 
        while(ii>=1){
            OO[ii] = (OO[ii+1] | b[ii]) ; 
            ii--;
        }
        
        int j = 2 ; 
        while(j<=k){
            
            /*
            int p5 = 0 ; 
            int idx = i ;
            int sum  = 0 ; 
            while(idx>=j){
                
                
                int p1 = dp[idx-1][j-1] + (sum|b[idx]);
                
                sum = (sum | b[idx]);
                p5 = max(p5,p1);
                
                
                idx--;
            }
            dp[i][j] = p5 ; 
            */
            int p5 = 0 ; 
            for (int c = 18; c >= 0; c--) {
                int idx = check[c] ; 
                
                if(idx>=j){
                    int p1 = dp[idx-1][j-1] + OO[idx];
                    p5 = max(p5,p1);
                }
                
            }
            
            dp[i][j] = p5 ;
            
            j++;
        }
        
        for (int j = 18; j >= 0; j--) {
            int k = b[i] >> j; 
            if (k & 1) {
                check[j] = i ; 
            } 
        }  
        
        
        i++;
    }
    
    
    cout<<dp[n][k] ; 
    
    
    return 0 ; 
}