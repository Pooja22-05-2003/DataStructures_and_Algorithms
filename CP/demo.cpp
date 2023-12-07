// /*
// Approach:

// -> Here we need to find 2 things.
// -> 1=First is find the shortest length having sum is equal to k
// -> 2=Second using (fixed size sliding window) find the number of subbaray having sum k with that shortest legth (k size)

// -> For first using prefix sum , find out the ans(k)
// -> Now using i and j pointer sliding window, find the count of subarray having that length and sum is equal to k
// -> Using 1 based indexing , so keep in mind that(small error u did while coding)


// */


// // TC=O(N)
// // SC=O(N)


// #include <bits/stdc++.h>
// using namespace std;

// int solve(vector<int>& nums,int n,int k) {
//     unordered_map<int,int> prefix;
//     int sum=0;
//     prefix[0]=0;

//     int m=1;
//     int miniLen=INT_MAX;
//     while(m<=n){
//         sum+=nums[m];
        
//         if(prefix.find(sum-k)!=prefix.end()){
//             miniLen=min(miniLen,(m-prefix[sum-k]));
//         }
//     prefix[sum]=m;
//     m++;
//     }

//     // fixed size sliding window
//       int cnt=0;

//     //   cout<<"miniLen:"<<miniLen<<endl;
//     if(miniLen!=INT_MAX){
  
//     int i=1;
//     int j=1;
//     int k1=miniLen;
//     int summ=0;
//     while(j<=n){
//         summ+=nums[j];
//         if(j-i+1<k1) j++;
//         else if(j-i+1==k1){
//             // cout<<"sum:"<<summ<<" k:"<<k<<endl;
//             if(summ==k) cnt++;
//             summ-=nums[i];
//             i++;
//             j++;
//         }
//       }
//     }

//     return cnt;

// }

// int main()
// {
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
//     //**********


//     //*********
//     // 1-- based indexing are used here

//     int n;
//     cin>>n;

//     int k;
//     cin>>k;
   
//     vector<int> arr(n+1);
//     for(int i=1;i<=n;i++){
//         cin>>arr[i];
//     }

//     cout<<solve(arr,n,k);
// }






// /*

// input :
// 8
// 15
// 10 5 2 7 1 9 8 7


// output:
// 2


// */



#include <iostream>
using namespace std;
int solve(int N,int X, int K){
    int No_of_boy=X;
    int No_of_girl=N-X;
    int rem_Boy=No_of_boy%K;
    int rem_Girl=No_of_girl%K;
    if(rem_Boy>=rem_Girl) return rem_Boy-rem_Girl;
    else return rem_Girl-rem_Boy;
}
int main() {
	// your code goes here
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	int n;
    cin>>n;
	while(n>0){
	    int N,X,K;
	    cin>>N;
	    cin>>X;
	    cin>>K;
	    cout<<solve(N,X,K)<<endl;
	    n--;
	}
	return 0;
}