/*
Approach :
1. Brute Force Approach will not work in this case.(T*n)=> (10^5*10^9)==> 10^14
2. If the number n=7 [111], then the most significant bit(is at 2nd bit ). we need to find a element which has 0 at the 2nd bit first time
and it should be smaller than 7.
3. Trick⭐: (2^ith col-1) will definitely given 0 at the ith col.
Ex= (2^2-1)=3, 3 is the first element which has 0 at the 2nd col bit.

4. Now 2nd bit 0 is done.....but also we need to convert the first and 0th bit to 0.
5. The number greater than 3 , definitely contain 0 as the bit at 1st and 0th col.
6. 3=[011] , 4=[100], as u see here 4 contain 0 at both 0th and 1st bit.

7. So the problem boils down to, find the most significant bit(col) in n and return number(2^col-1).

*/

// TC=O(N*30)==(10^6)
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
