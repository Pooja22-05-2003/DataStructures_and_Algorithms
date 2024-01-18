#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
ll dp[100][105];

int main() {
    
    ll n;
    cin>>n; 
    ll a[n+1]={0};
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll b = 0 ; 
    for(ll i=1;i<=n;i++){
        ll j=0;
        while(j<=100){
            
            ll l = i - 1 ; 
            ll u = 0 ; 
            while(l>=1){
                if(a[l]+j==a[i]){
                    ll p = dp[l][j];
                    u = max(u,p);
                }
                l--;
            }
            dp[i][j] = u + 1 ; 
            b = max(b,dp[i][j]);
            j++;
        }
    }
    
    cout<<b;
    
    
    return 0;
}