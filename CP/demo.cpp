/*

*/

#include<bits/stdc++.h>
using namespace std;

int  solve(vector<int>arr, int n ){

    vector<int>count(32,0);
    for(int i=0;i<=31;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            int el=arr[j];
            int ith_bit=(el>>i);
            if((ith_bit&1)==0)
            {
               
            }
            else{
                cnt++;
            }
        }
      
        count[i]=cnt;
    }
    int num_ans=0;

    for(int i=0;i<=31;i++)
    {
        if(count[i]==0) 
        {}
        else num_ans+=(2<<i);
    }
    return num_ans;
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
4
7 1 3 5


Output 1:
14




input2 :


Output2:



*/


