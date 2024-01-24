// TC=O(n2)
// SC=O(n2)

#include <bits/stdc++.h>
using namespace std;
//dp1===donniiieeeee====>first..second
//dp2====roniiiie{i,j}--->first...second

// dp1.first and dp2.first (Will always store ans for Donnie)
// dp1.second and dp2.second (Will always store ans for Ronnie)
map<pair<int,int>,pair<int,int>>dp1;
map<pair<int,int>,pair<int,int>>dp2;

pair<int,int> r(int i,int j,vector<int>a);
pair<int,int> d(int i,int j,vector<int>a);


pair<int,int> r(int i,int j,vector<int>a)
{
     // 1st case that ans is already calculated
    if(dp2.find({i,j})!=dp2.end()){
        return dp2[{i,j}];
    }

    if(i==j){
        pair<int,int>d1;
        d1.first=0;
        d1.second=a[i];
        dp1[{i,j}]=d1;
        return d1;
        
    }


    pair<int,int>possibility1,possibility2;
    possibility1.first=d(i+1,j,a).first;
    possibility1.second=d(i+1,j,a).second+a[i];

    possibility2.first=d(i,j-1,a).first;
    possibility2.second=d(i,j-1,a).second+a[j];


    if(a[i]>a[j])
    {
        dp2[{i,j}]=possibility1;
        return possibility1;
    }

    // here one more can also lie, that is when both el at left and right are equal , so follow the optimial path in that case.
    else if (a[i]==a[j])
    {
        
    if((possibility1.first-possibility1.second)>=(possibility2.first-possibility2.second))
    {
        dp2[{i,j}]=possibility1;
        return possibility1;
    }

    else 
    {
    
        dp2[{i,j}]=possibility2;
        return possibility2;
    
    }
    }
    else 
    {
    
        dp2[{i,j}]=possibility2;
        return possibility2;
    
    }
}
pair <int,int> d(int i,int j,vector<int>a){

    // 1st case that ans is already calculated
    if(dp1.find({i,j})!=dp1.end()){
        return dp1[{i,j}];
    }

    if(i==j){
        pair<int,int>d1;
        d1.first=a[i];
        d1.second=0;
        dp1[{i,j}]=d1;
        return d1;
        
    }


    pair<int,int>possibility1,possibility2;
    possibility1.first=a[i]+r(i+1,j,a).first;
    possibility1.second=r(i+1,j,a).second;

    possibility2.first=a[j]+r(i,j-1,a).first;
    possibility2.second=r(i,j-1,a).second;


    if((possibility1.first-possibility1.second)>=(possibility2.first-possibility2.second))
    {
        dp1[{i,j}]=possibility1;
        return possibility1;
    }

    else 
    {
    
        dp1[{i,j}]=possibility2;
        return possibility2;
    
    }
}
int solve(int n,vector<int>arr)
{
;
    pair<int,int> ans=d(1,n,arr);
    cout<<"Optimal path sum:"<<ans.first<<" "<<" Greedy path sum:"<<ans.second<<endl;
    return (ans.first-ans.second);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********
    //

    //*********

    int n;
    cin>>n;

    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<solve(n,arr);

    return 0;
}

/*
// input1 :
4
7 5 18 9


// output1:
Optimal path sum:25  Greedy path sum:14
11

// input1 :
4
7 3 12 6



// output1:
Optimal path sum:19  Greedy path sum:9
10

*/







