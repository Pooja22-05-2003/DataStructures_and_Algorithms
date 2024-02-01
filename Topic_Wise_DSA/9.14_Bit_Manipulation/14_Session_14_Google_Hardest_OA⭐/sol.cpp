// TC=O(N*30)
// SC=O(32)
#include <bits/stdc++.h>
using namespace std;


int solve(int n, vector<int>arr)
{
    // hashmap stroing freq=1 and 0
    int ans=0;

    for(int j=30;j>=0;j--)
    {
      
        int cnt_1=0;
        int cnt_0=0;
        for(int i=1;i<=n;i++)
        {
            int num=arr[i];
            int g=(num>>j);
            if((g&1)==1)
            {
                cnt_1++;
            }
            else cnt_0++;

        }
        ans+=((cnt_1)*(cnt_0))*(1<<j);
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

    // Enter the decimal number.

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }


    cout << solve(n,arr);
    return 0;
}

/*
// input1 :
5
2 7 1 5 8



// output1:
74


// input 2 :


// output 2:







*/
