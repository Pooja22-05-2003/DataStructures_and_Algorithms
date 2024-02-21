/*
Approach :

Given an array, find the length of the maximum length of the subarray having AND of the subarray is As maximum as possible.

1. AND of two number van be less than or equal to the maximum number.
2. If both numbers are different , then their AND is less.
3. If both numbers are same , then there AND is same value. But AND of two number can never increase by the maximum value.
4. If take 2 or more elements in the subarray, then if they are differenct then their AND will be differernt.


5. step1: Find the maximum value among the array.
6. Find the maximum lenght of the subarray having all element equal to that maximum element.

*/

// TC=O(n)
// SC=O(1)
#include<bits/stdc++.h>
using namespace std;

int  solve(vector<int>arr, int n ){
    int maxel=arr[1];
    int i=2;
    while(i<=n)
    {
        maxel=max(maxel,arr[i]);
        i++;
    }


    int len=0;
    int ans=1;
    i=2;
    
    while(i<=n)
    {
        if(arr[i]==maxel && (arr[i-1]==maxel))
        {
            len++;
        }
        else len=0;
        ans=max(ans,len+1);
        i++;
    }

    return ans;
}  


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********

    int n ;
    cin>>n;

  

    vector<int>arr(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    
    int ans=solve(arr,n);
    cout<<ans<<endl;

	return 0;
}
	

/*
input1 :
5
2 2 2 2 2 


Output 1:
5



input2 :
5
1 2 2 2 0 

Output2:
3


*/


