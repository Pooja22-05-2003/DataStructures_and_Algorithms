// TC=O(N2)
// SC=O(1)
#include<bits/stdc++.h>
using namespace std;

int solve(int n ,vector<int>arr){
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int OR_operation=arr[i] | arr[j];
            ans=ans+OR_operation;

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
4
1 2 3 4

// output1:
27


// input 2 :


// output 2:







*/

