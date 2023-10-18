// TC=O(n+q)
// SC=O(n)


#include <bits/stdc++.h>
using namespace std;


int solve(vector<int>arr,int l, int r){
    int n=arr.size();
    vector<int>prefixArr(n+1,0);
    prefixArr[0]=0;

    for(int i=1;i<=n;i++){
    int ind=i-1;  // arr index and i will correspond to prefix arr
    prefixArr[i]=prefixArr[i-1]+arr[ind];
    // cout<<"i:"<<i<<"prefix[i]:"<<prefixArr[i];
    }

    /*
    5
Normal arr:
  0 1 2 3 4
  3 0 4 1 1

prefix arr:
0 1 2 3 4 5
0 3 3 7 8 9

query
1 3

l=2  (new left)
r=4  (new right)
*/

    int newleft=l+1;
    int newright=r+1;
    int ans=prefixArr[newright]-prefixArr[newleft-1];
    return ans;

}

int main()
{

    //**********

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //*********

    int n;
    cin >> n ;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int Queries;
    cin>>Queries;

    while(Queries>0){
        int left , right;
        cin>>left>>right;
        int ans=solve(arr,left,right);
        cout<<ans<<endl;

        Queries--;
    }
}