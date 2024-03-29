/*
Optimized_sol Appoach:
1. Calculate bitwise OR for all the ith col.
2. For calcualting 1, let's think that the first col all element are present in binary form.
3. Then follow the sit mehtod of binary number subarray sum calculation for creating first funciton/
4. Then for final sum, add all the ithcol sum * (2^i) [ i will vary from 0 to 30]
5. Finally return the ans.

*/



#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> arr)
{
    int n = arr.size();
    vector<int> recent(n, -1);
    if (arr[0] == 1)
        recent[0] = 1;

    // Start loop from i = 1
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 1)
            recent[i] = i;
        else
            recent[i] = recent[i - 1];
    }

    int ans = 0;
    vector<int> sum(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (recent[i] != -1)
            sum[i] = recent[i] + 1;
        ans = ans + sum[i];
    }
    return ans;
}
int solve(vector<int> arr, int n)
{
    vector<vector<int>> BinaryArr(n, vector<int>(31, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            int el = arr[i];
            int ith_bit = (el >> j) & 1;
            BinaryArr[i][j] = ith_bit;
            // cout<<"i:"<<i<<" j:"<<j<<" B[i][j]:"<< BinaryArr[i][j]<<endl;
        }
    }
    int ans = 0;
    int ind = 0;
    for (int i = 0; i < 31; i++)
    {
        vector<int> temp;
        int j = i;
        for (int k = 0; k < n; k++)
        {
            temp.push_back(BinaryArr[k][j]);
        }

        //    cout<<"col:"<<i<<endl;
        //    for(auto it : temp) cout<<it<<",";
        //    cout<<endl;

        /*
 col:0 =>0,1,0,
 col:1=>1,0,0,
 col:2=>0,1,0,
 col:3=>0,0,1,
        */
        int tempsum = helper(temp);
        cout << "i:" << i << " tempsum:" << tempsum << endl;
        ans += tempsum * (pow(2, i));

        ind++;
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
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = solve(arr, n);
    cout << "ans:" << ans << endl;
    // cout << (2 | 5) << " ," << (2 | 8) << " ," << (5 | 8) << " ," << (2 | 5 | 8) << endl;
    return 0;
}

/*
input1 :
3
2 5 8

Output 1:
expected=50
output: 56 (Incorrect)




*/
