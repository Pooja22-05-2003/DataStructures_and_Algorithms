/*
Approach:
✨ Brute Force approach

1. Calculate the ratio of 0 and 1(not an correct way) , using prex array
2. No of 0 / No of 1 = x/y [Rewrite : (No of 0)*y==x*(No of 1) then do cnt++]
3. Repeat this for all the possbile subarray and is that subarray is satisifying the given condition , u can increment the count.

*/


// TC=O(n2)
// SC=O(n)


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr , int n , int x , int y) {
    int ans=0;
    vector<int> pref0(n+1,0);
    vector<int> pref1(n+1,0);

    for(int i=1;i<=n;i++){
        if(arr[i]==0){
            pref0[i]=pref0[i-1]+1;
            pref1[i]=pref1[i-1];
        }
        
        else if (arr[i]==1){
            pref1[i]=pref1[i-1]+1;
            pref0[i]=pref0[i-1];
        }
    }

    // for(int i=1;i<=n;i++){
    //     cout<<"Pref0 - i=>"<<i<<":"<<pref0[i]<<"Pref1"<<pref1[i]<<endl;
    // }
    //  iterate on all the subarray
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int cnt0=pref0[j]-pref0[i-1];
            int cnt1=pref1[j]-pref1[i-1];
            if((cnt0*y)==(cnt1*x)) ans++;
        }
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********


    //*********
    // 1-- based indexing are used here

    int n ;
    cin>>n;
    int x;
    cin>>x;
    int y;
    cin>>y;

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    cout<<solve(arr,n,x,y);
   
}






/*

input1 :
7
1
2
1 0 1 1 1 1 1


output1:
2


input2:
4
1
1
0 1 0 1

output2:
4







*/

