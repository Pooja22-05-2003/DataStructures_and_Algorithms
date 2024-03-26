/*
Approach:
1. In one Iteration find the minimum possible absolute difference and store those in vector pair ans(Store the pairs).
2. Then sort the answer vector.
3. Print that answer vector.


*/

// TC=O(n)
// SC=O(1)
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>arr, int n)
{
    sort(arr.begin()+1,arr.end());
    int min_Diff=INT_MAX;

    for(int i=2;i<=n;i++)
    {
        int d=arr[i]-arr[i-1];
        if(d<min_Diff)
        {
            min_Diff=d;
        }
    }

    for(int i=2;i<=n;i++)
    {
        int d=arr[i]-arr[i-1];
        if(d==min_Diff)
        {
            cout<<arr[i-1]<<" "<<arr[i]<<endl;
        }
    }

    


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
    cin >> n;

    vector<int>arr(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>arr[i]; 
    }

  
    // int ans = solve(arr, n);
    solve(arr, n);
    // cout << "ans:"<<ans<< endl;

    return 0;
}

/*
input1 :
4
4 2 1 3

Output 1:
1 2
2 3
3 4


input2 :
4
4 -2 -1 3

Output2:
-2 -1
3 4


Input 3:


Output3:




*/
