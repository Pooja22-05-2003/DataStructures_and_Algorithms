// TC=O(N)
// SC=O(N)
#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    int Most_significant_bit_col = 0;
    for (int i = 30; i >= 0; i--)
    {
        int g = (n >> i);

        if ((g & 1) == 1)
        {
            Most_significant_bit_col = i;

            break;
        }
    }

    return (pow(2, Most_significant_bit_col) - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********

    // Enter the decimal number.
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}

/*
// input1 :
3
7
9
17

// output1:

3
7
15



// input 2 :


// output 2:







*/
