// TC=O(N*30)
// SC=O(N)
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> arr)
{
    int ans = 0;
    // msb(most signinficant bit)->cnt
    unordered_map<int, int> mp;


    for (int i = 1; i <=n; i++)
    {
        int num = arr[i];
        int msb = -1;

        for (int j = 30; j >= 0; j--)
        {
            int g = (num >> j);
            if ((g & 1) == 1)
            {
                msb = j;
                break;
            }
        }
        // cout<<"msb:"<<msb<<endl;
        mp[msb]++;

        for (int j = 0; j <= 31; j++)
        {

            // pairs having msb at different bit positions will have xor>and
            if (mp.find(j) != mp.end() && j != msb)
            {

                ans += mp[j];
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

    cout << solve(n, arr);
    return 0;
}

/*
// input1 :
4
4 3 5 2



// output1:
4



// input 2 :


// output 2:







*/
