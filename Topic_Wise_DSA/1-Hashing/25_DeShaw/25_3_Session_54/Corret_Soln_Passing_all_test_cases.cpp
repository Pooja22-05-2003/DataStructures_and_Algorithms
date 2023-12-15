#include <bits/stdc++.h>
 
using namespace std; 
typedef long long int ll; 
 
bool check(ll n,ll i,ll j,ll b[]) {
 
    if(i==1 && j==n){
        return false;
    }
 
 
    ll u = 2;
    while (u <= i) {
        if (b[u - 1] <= b[u]) {
            // Do something if needed
        } else {
            return false;
        }
        u++;
    }
 
 
    // if(i==1 && j==1){
    //     cout<<"lol";
    // }
 
 
 
    u = j + 2;
    while (u <= n) {
        if (b[u - 1] <= b[u]) {
            // Do something if needed
        } else {
            //cout<<b[u-1]<<" "<<b[u];
            //cout<<'\n';
            return false;
        }
        u++;
    }
 
 
    if (b[i - 1] <= b[j + 1]) {
        return true;
    }
 
    return false;
}
 
int main() {
    ll n; // Assuming n is defined somewhere in your code
    cin>>n ; 
 
    ll b[n+2] = {0};
    b[0] = -1e18 ; b[n+1] = 1e18 ; 
 
    ll i = 1 ; 
    while(i<=n){
        cin>>b[i];
        i++;
    }
    
    
 
 
 
    int count = 0;
 
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            // check if [i.....j] is good or not
            if (check(n,i,j,b)==true) {
                
                // cout<<i<<" "<<j;
                // for(ll l=1;l<=n;l++){
                // 	if(l>=i && l<=j){

                // 	}
                // 	else 
                // 	{
                // 		cout<<b[l]<<" ";
                // 	}
                	
                // }
                
                
                //cout<<'\n';
                count++;
            }
        }
    }
 
    // The variable 'count' now holds the number of good pairs
    cout<<count ; 
    return 0;
}
 