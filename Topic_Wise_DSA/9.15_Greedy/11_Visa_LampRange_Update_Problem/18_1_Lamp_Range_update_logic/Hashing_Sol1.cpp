// https://ideone.com/bZKP7t

#include <iostream>


using namespace std;

int main() {
    int n, Q, p;
    cin >> n >> Q >> p;

    int b[100001] = {0}; // Assuming l, r <= 100000

    for (int i = 1; i <= Q; i++) {
        int L, R;
        cin >> L >> R;
        b[L] = b[L] + 1;

        if (R + 1 <= n) {
            b[R + 1] = b[R + 1] - 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        b[i] = b[i] + b[i - 1];
    }

    for (int i = 1; i <= p; i++) {
        int y;
        cin >> y;
        cout << b[y] << endl;
    }

    return 0;
}



/*

output :
stdin copy
15 3 6 
1 7 
5 11
7 9 
7 1 5 10 9 15 
stdout copy
3
1
2
1
2
0
*/