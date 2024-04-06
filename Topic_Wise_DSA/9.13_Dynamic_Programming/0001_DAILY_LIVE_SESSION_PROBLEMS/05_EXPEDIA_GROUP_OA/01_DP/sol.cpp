
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll ; 


// int main() {
//      #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
//     //**********
// 	ll t ; 
// 	cin>>t;
// 	while(t--){
// 		ll n ; 
// 		cin>>n ; 
// 		ll xr = 0 ; 
// 		ll i = 1 ; 

// 		ll odd = 0 ; //number of prefix xor which has odd  set bit 
// 		ll even = 1 ; //number of prefix xor which has even set bit 
// ll sum = 0 ;         
// 		while(i<=n){
// 			ll number ; 
// 			cin>>number;
// 			xr = (xr^number); //xor of elements from [1....i]
// 			ll count = __builtin_popcount(xr);
// 			if(count%2==0){
// 				sum = sum + odd ; 
// 				even++;
// 			}
// 			else{
// 				sum = sum + even ; 
// 				odd++;
// 			}
// 			i++;
// 		}
// 		cout<<sum;
// 		cout<<'\n';
// 	}
	


// 	return 0 ;
// }	


// /*
// // input1 :
// 1
// 3
// 1 2 4 



// // output1:
// 4




// // input 2 :



// // output 2:

// */

#include<bits/stdc++.h>
using namespace std;

int solution(vector<int>&nums, int k){
	int n = nums.size(), i, j;
	int dp[n+1][k+1]; // dp(i, j) -> denotes maximum sum under j when we consider only first i array elements

	/*
		base cases :
			1. when i = 0 or j = 0, dp(i, j) = 0
	*/
	for(i = 0; i <= n; i++){
		dp[i][0] = 0;
	}
	for(j = 1; j <= k; j++){
		dp[0][j] = 0;
	}


	//fill the dp in iterative way
	for(i = 1; i <= n; i++){
		for(j = 1; j <= k; j++){
			/*
				At a given moment, we have two choices, either we can take i'th element
				into our answer subset OR we ignore that element;
			*/
			dp[i][j] = dp[i-1][j]; //if we ignore the i'th element
			if(nums[i] <= j){
				dp[i][j] = max(dp[i-1][j-nums[i]] + nums[i], //if we consider i'th element in our set
								dp[i][j]); // take maximum of the case which gives us the maximum answer
			}
		}
	}

	return dp[n][k]; //dp(n, k) will have our answer
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
	int n, k;	
	cin>>n;	
	cin>>k;
	vector<int> nums(n);	
	
	for(int i = 1; i <=n; i++)
		cin>>nums[i];	
	
	
	cout<<solution(nums, k)<<endl;	
	return 0;
}


/*
input :
5 
10
1 2 3 12 3


Output :
9


input :
8 
15
1 2 3 4 5 6 7 16


Output :
15
*/