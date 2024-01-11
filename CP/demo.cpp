// TC= O(N2)
// SC= O(N)
#include<bits/stdc++.h>
using namespace std;
   
    int  solve(vector<int> a , vector<int>&b, int n ) 
{
   
   vector<int> dp(n+1,0);

   dp[0]=0;
   dp[1]=a[1];

   int i=2;
   while(i<=n){
    int temp=dp[i-1]+a[i];

    int j=i-1;
    int sum=b[i]+b[i-1];
    while(j>=1){
        int t=sum+dp[j-1];
        temp=min(temp,t);
        j--;
        sum+=b[j];
    }
    dp[i]=temp;
    i++;
   }

   return dp[n];
   
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********

    int n;
    cin>>n;

    vector<int>arr1(n+1);
    vector<int> arr2(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }

    for(int i=1;i<=n;i++){
        cin>>arr2[i];
    }

    cout<<solve(arr1,arr2,n);

	return 0;
}
	


/*
// input1 :
5
3
5 
2 
1 
9 
1 
1 
10 
5 
3 


// output1:
12


// input 2 :
12
16
20
12
12
8
2
3
8
17
3
14
8
16
17
1
2
20
17
1
3
9
8
10
16


// output 2:
84


154 but output is 84
*/