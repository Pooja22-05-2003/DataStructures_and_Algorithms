// TC=O(N)
// SC= O(81)== O(1) [ hashmap will store in worst case 999999999(sum)=81]

#include <bits/stdc++.h>
using namespace std;
int DigitSum(int n){
    int ans=0;
    while(n>0){
        ans+=n%10;
        n=n/10;
    }

    return ans;
}
int solve(vector<int> &arr ,int n){

    unordered_map<int,int>Map;

    int maxx=-1;
    for(int i=0;i<arr.size();i++)
    {
        
        int digitsum=DigitSum(arr[i]);
       
        if(Map.find(digitsum)!=Map.end()) 
        {
       
            int sum=arr[i]+Map[digitsum];
             maxx=max(maxx,sum);
            Map[digitsum]=max( Map[digitsum] , arr[i]);
        }
        else Map[digitsum]=arr[i];
    }

    return maxx;
    
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

    int n;
    cin >> n ;
    vector<int> arr1(n+1);


    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }

    cout<<solve(arr1,n )<<endl;
}






/*
input :
4
51 71 17 42

output :
93


input :
4
51 71 17 42

output :
93


input :
3
51 32 43

output :
-1

*/




