// ideone link : https://ideone.com/Kt9Wtq
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll dp[100005][2];

int main() {
    
    ll n;cin>>n;
    ll b[n+1]={0};
    for(ll i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b+1,b+n+1);


    ///----------
    dp[1][0] = -1e18 ; 
    dp[1][1] = -1e18 ; 
    cout<<dp[1][0]<<"\n";
    if((b[2]-b[1])%2==0){
        dp[2][0] = 2 ; 
        dp[2][1] = -1e18 ; 
    }
    else{
        dp[2][1] = 2 ; 
        dp[2][0] = -1e18;
    }
    cout<<dp[2][0]<<"\n";
    
    ll answer = 0 ;
    for(ll i=3;i<=n;i++){
        dp[i][0] = -1e18;
        dp[i][1] = -1e18;
        ll j = 2 ; 
        while(j<=i-1){
            ll d = b[i] - b[j] ; 
            if(d%2==0){
                
                
                if(dp[j][0]<0){
                    dp[i][0] = 2 ; //j.....i = subset of 2 guys selected. 
                }
                else{
                    dp[i][0] = max(dp[i][0],1 + dp[j][0]);
                }
                
                
                dp[i][1] = max(dp[i][1],1 + dp[j][1]);
                
                
                
            }
            else{
                dp[i][0] = max(dp[i][0],1 + dp[j][1]);
                
                
                 if(dp[j][0]<0){
                     dp[i][1] = 2 ; //j.....i = subset of 2 guys selected. 
                }
                else{
                  dp[i][1] = max(dp[i][1],1 + dp[j][0]);
                }
                
                
                
                
                
                
            }
            
            j++;
        }
        
        if((b[i]-b[1])%2==0){
            ll u = 2 ; 
            dp[i][0] = max(dp[i][0],u);
        }
        else{
            ll u = 2 ; 
            dp[i][1] = max(dp[i][1],u);
        }
        
        
        
        cout<<dp[i][0]<<'\n';
        answer = max(answer,dp[i][0]);
    }
    cout<<answer ; 
    return 0;
}








