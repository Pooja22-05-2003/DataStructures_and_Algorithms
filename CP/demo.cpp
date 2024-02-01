// TC=O(N*30)
// SC=O(32)
#include <bits/stdc++.h>
using namespace std;


int solve(int n, vector<int>a,vector<int>b)
{
    // hashmap stroing freq=1 and 0
    vector<int>freq_b_1(32,0);
    vector<int>freq_b_0(32,0);

    for(int i=1;i<=n;i++)
    {
        int num=b[i];
        for(int j=30;j>=0;j--)
        {
            int g=(num>>j);
            if((g&1)==1)
            {
                freq_b_1[j]++;
            }
            else freq_b_0[j]++;

        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int num=a[i];
        for(int j=30;j>=0;j--)
        {
            int g=(num>>j);
            if((g&1)==1)
            {
                // it can pair with all the 0 (1^0=1)
                int cnt=freq_b_0[j];
                ans=ans+(cnt*(1<<j));

            }
            else if((g&1)==0)
            {
                int cnt=freq_b_1[j];
                ans=ans+(cnt*(1<<j)); 
            }

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
5 4 3 2 1
1 2 3 4 5 



// output1:
84


// input 2 :


// output 2:







*/
