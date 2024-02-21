/*

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


