// TC=O(N*q)     N time for each test case
// SC=O(N)       dp array space complexity

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll max(ll a, ll b, ll c) {
    return max(a, max(b, c));
}

ll min(ll a, ll b, ll c) {
    return min(a, min(b, c));
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin >> t; // taking input of all the test cases

    while (t--) {
        ll b;
        cin >> b; // number of characters in 1 test case
        ll i;
        ll dp1[b + 1];
        ll dp2[b + 1];
        dp1[0] = 1;
        dp2[0] = dp1[0];

        for (i = 1; i <= b; ++i) {
            char g; // taking input of all the characters one by one
            cin >> g;
            if (g == '+') {
                ll e;
                cin >> e; // taking the input of the number after + sign
                dp1[i] = max(dp1[i - 1] + e, dp2[i - 1] + e, dp1[i - 1]);
                dp2[i] = min(dp1[i - 1] + e, dp2[i - 1] + e, dp2[i - 1]);
            } else if (g == '-') {
                ll e;
                cin >> e; // taking the input of the number after - sign
                dp1[i] = max(dp1[i - 1] - e, dp2[i - 1] - e, dp1[i - 1]);
                dp2[i] = min(dp1[i - 1] - e, dp2[i - 1] - e, dp2[i - 1]);
            } else if (g == '*') {
                ll e;
                cin >> e; // taking the input of the number after * sign
                dp1[i] = max(dp1[i - 1] * e, dp2[i - 1] * e, dp1[i - 1]);
                dp2[i] = min(dp1[i - 1] * e, dp2[i - 1] * e, dp2[i - 1]);
            } else if (g == '/') {
                ll e;
                cin >> e; // taking the input of the number after / sign
                dp1[i] = max(dp1[i - 1] / e, dp2[i - 1] / e, dp1[i - 1]);
                dp2[i] = min(dp1[i - 1] / e, dp2[i - 1] / e, dp2[i - 1]);
            } else {

                // If the input is N(Means negative of the number)
                dp1[i] = max(-1 * dp1[i - 1], -1 * dp2[i - 1], dp1[i - 1]);
                dp2[i] = min(-1 * dp1[i - 1], -1 * dp2[i - 1], dp2[i - 1]);
            }
        }
        cout << dp1[b] << "\n";
    }

    return 0;
}



/*
input1 :
2
3
N
- 2
N
3
- 1
* 4
/ 2



output1:
3 (1*(-1)=>-1-2=>-3=>-(-3)=>3)

4

input 2 :


output 2:





input3:

output3:




*/
