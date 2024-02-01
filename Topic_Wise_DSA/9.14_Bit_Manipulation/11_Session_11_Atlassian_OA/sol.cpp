/*


Approach : 

First you pick up all the numbers whose 0th bit is 1 ; whatever their size it can be your answer because the final bitwise AND!=0 ; as the the 0th bit of end result will always be 1 -> g1

-> You can do same as above for the 1st bit -> g2 

-> You can do same as above for the 2nd bit -> g3 
.
.
.
.
.
.
.
-> You can do the same as above for the 30th bit -> g30

2. For each number check for the ith bit. If it is not 0, then that numeber will contribute to the subsequence.
3. For each bit fronm 0 to 30, at each bit, count the number of set bits.
max count of bit will contribute to the maximum subsequence.

*/

// TC=O(N*30)
// SC=O(1)
#include <bits/stdc++.h>
using namespace std;


int solve(int n, vector<int>arr)
{
    int maxlen=0;

    vector<int>hashmap(32,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=30;j>=0;j--)
        {
            int num=arr[i];
            int g=(num>>j);
            if((g&1)==1)
            {
                hashmap[j]=hashmap[j]+1;

            }
        }
    }

    for(int i=0;i<=32;i++)
    {
        maxlen=max(maxlen,hashmap[i]);
    }

    return maxlen;
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
7 4 11 8 3



// output1:
3



// input 2 :


// output 2:







*/
