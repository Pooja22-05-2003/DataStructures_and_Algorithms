
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ; 


int main() {
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
	ll t ; 
	cin>>t;
	while(t--){
		ll n ; 
		cin>>n ; 
		ll xr = 0 ; 
		ll i = 1 ; 

		ll odd = 0 ; //number of prefix xor which has odd  set bit 
		ll even = 1 ; //number of prefix xor which has even set bit 
ll sum = 0 ;         
		while(i<=n){
			ll number ; 
			cin>>number;
			xr = (xr^number); //xor of elements from [1....i]
			ll count = __builtin_popcount(xr);
			if(count%2==0){
				sum = sum + odd ; 
				even++;
			}
			else{
				sum = sum + even ; 
				odd++;
			}
			i++;
		}
		cout<<sum;
		cout<<'\n';
	}
	


	return 0 ;
}	


/*
// input1 :
1
3
1 2 4 



// output1:
4




// input 2 :



// output 2:

*/