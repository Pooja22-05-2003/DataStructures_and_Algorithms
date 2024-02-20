/*

*/

// TC=O(n)
// SC=O(n)
#include<bits/stdc++.h>
using namespace std;

int  solve(vector<int>arr, int n , int op){

    sort(arr.begin(),arr.end());


    vector<int>extra;

    // cout<<"arr.size():"<<arr.size()<<endl;
    // for(auto it : arr) cout<<it<<endl;
    // cout<<";"<<endl;
    int distinct=0;
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
       if(arr[i-1]==arr[i]) cnt++;
       else 
       {
       
        distinct++;
        // cout<<"i:"<<i<<"distinct:"<<distinct<<endl;
        if(cnt>1) extra.push_back(cnt-1);
        cnt=1;
       } 
    }



    if(cnt>1) 
    {extra.push_back(cnt-1);
    distinct++;
    }
    int ans=0;

    int totalextra=0;
    for(auto it : extra) totalextra+=it;

    cout<<"distinct:"<<distinct<<" totalextra:"<<totalextra<<endl;
    ans=max(0,distinct-max(0,(op-totalextra)));
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

    int operations;
    cin>>operations;

    vector<int>arr(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];

    }
    
    int ans=solve(arr,n,operations);
    cout<<ans<<endl;

	return 0;
}
	

/*
input1 :
6
2
1 1 1 2 3 2


Output 1:
3



input2 :
6
5
1 1 2 2 3 3

Output2:
1 (distinct:3 totalextra:3)


*/


