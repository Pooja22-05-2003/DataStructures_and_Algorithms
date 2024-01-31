/*
1. For optimization , we can count the number of 1's till index i-1.
2. Iterate through the array.
3. For any pair , we have 2 options , whether it is valid pair or it is invalid pair.
4. For valid pair among 2 elements, if even one element is 1, then it is valid.
5. So while iterating if the current element is 1, then all the elemnts left to it are valid, whether it is 1 or 0.
6. If the current element is 0, all the elements which are 1 to the left of it are valid. (So add the cnt_1 int ans).

*/

// TC=O(N)
// SC=O(1)
#include<bits/stdc++.h>
using namespace std;

int solve(int n ,vector<int>arr){
    int ans=0;
    int cnt_1=0;
    for(int i=1;i<=n;i++)
    {
      if(arr[i]==1)
      {
        ans+=i-1; // 1 based indexing
        cnt_1++;
      }
      else {
        ans=ans+cnt_1;
      }

    }

    return ans;
    
}  

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
     
    // Enter the decimal number.
    int n;
    cin>>n;

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    cout<<solve(n,arr)<<endl;
	return 0;
}
	


/*
// input1 :
8
0 1 1 0 0 0 1 1

// output1:
22


// input 2 :


// output 2:







*/

