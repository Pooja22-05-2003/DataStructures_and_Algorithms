/*
Approach:
✨ Optimal approach

1. Calculate the ratio of 0 and 1(not an correct way) , using prex array
2. No of 0 / No of 1 = x/y [Rewrite : (No of 0)*y==x*(No of 1) then do cnt++]
3. Maintain one unordered map , which will maintain the count LHS which is same as RHS

1,2,3...i......n
for any index i, we calaculate RHS and in unordered , we try to know for i=j-1 to 1 ...(which we can easiyly get thorugh hashed array)the count of LHS which is equal to RHS, and we will add that in our answer
(pref0[j]-pref0[i-1])*y=(pref1[j]-pref1[i-1])*x

((pref0[j]*y)-(pref0[i-1]*y))=((pref1[j]*x)-(pref1[i-1]*x))

make i variable one side and j another side
(pref0[i-1]*y)-(pref1[i-1]*x)(LHS)=(pref0[j]*y)-(pref1[j]*x)(RHS)

Means we are directly calculating the number of good subarray from index 1 to j



*/


// TC=O(n)
// SC=O(n)


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr , int n , int x , int y) {
    int ans=0;
    vector<int> pref0(n+1,0);
    vector<int> pref1(n+1,0);

    unordered_map<int,int> mp;
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

    int j=1;
    while(j<=n){
        int LHS=(pref0[j-1]*y)-(pref1[j-1]*x);
        mp[LHS]++;

        int RHS=(pref0[j]*y)-(pref1[j]*x);
        ans+=mp[RHS];
        j++;
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

