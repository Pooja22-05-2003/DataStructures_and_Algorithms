#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll max(ll a, ll b, ll c) {
    return max(a, max(b, c));
}

ll min(ll a, ll b, ll c) {
    return min(a, min(b, c));
}

ll calculateDP(ll i, ll* dp1, ll* dp2, ll* numbers, char* operations) {
    if (i == 0) {
        dp1[i] = 1;
        dp2[i] = dp1[i];
        return dp1[i];
    }

    char g = operations[i - 1];
    ll e = numbers[i - 1];

    if (g == '+') {
        dp1[i] = max(calculateDP(i - 1, dp1, dp2, numbers, operations) + e, dp2[i - 1] + e, calculateDP(i - 1, dp1, dp2, numbers, operations));
        dp2[i] = min(calculateDP(i - 1, dp1, dp2, numbers, operations) + e, dp2[i - 1] + e, dp2[i - 1]);
    } else if (g == '-') {
        dp1[i] = max(calculateDP(i - 1, dp1, dp2, numbers, operations) - e, dp2[i - 1] - e, calculateDP(i - 1, dp1, dp2, numbers, operations));
        dp2[i] = min(calculateDP(i - 1, dp1, dp2, numbers, operations) - e, dp2[i - 1] - e, dp2[i - 1]);
    } else if (g == '*') {
        dp1[i] = max(calculateDP(i - 1, dp1, dp2, numbers, operations) * e, dp2[i - 1] * e, calculateDP(i - 1, dp1, dp2, numbers, operations));
        dp2[i] = min(calculateDP(i - 1, dp1, dp2, numbers, operations) * e, dp2[i - 1] * e, dp2[i - 1]);
    } else if (g == '/') {
        dp1[i] = max(calculateDP(i - 1, dp1, dp2, numbers, operations) / e, dp2[i - 1] / e, calculateDP(i - 1, dp1, dp2, numbers, operations));
        dp2[i] = min(calculateDP(i - 1, dp1, dp2, numbers, operations) / e, dp2[i - 1] / e, dp2[i - 1]);
    } else {
        dp1[i] = max(-1 * calculateDP(i - 1, dp1, dp2, numbers, operations), -1 * dp2[i - 1], calculateDP(i - 1, dp1, dp2, numbers, operations));
        dp2[i] = min(-1 * calculateDP(i - 1, dp1, dp2, numbers, operations), -1 * dp2[i - 1], dp2[i - 1]);
    }

    return dp1[i];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin >> t;

    while (t--) {
        ll b;
        cin >> b;

        ll i;
        ll dp1[b + 1];
        ll dp2[b + 1];
        ll numbers[b];
        char operations[b];

        for (i = 0; i < b; ++i) {
            cin >> operations[i] >> numbers[i];
        }

        ll result = calculateDP(b, dp1, dp2, numbers, operations);
        cout << result << "\n";
    }

    return 0;
}