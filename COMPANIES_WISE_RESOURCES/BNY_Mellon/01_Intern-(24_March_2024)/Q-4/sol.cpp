#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
using namespace std;

string solve(int n, int k, vector<string>& a) {
    for (int i = 0; i < a.size(); ++i) {
        a[i] = a[i].substr(0, a[i].find_last_not_of(' ') + 1);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < min(k, (int)a.size()); ++i) {
        string curr = "";
        for (char b : a[i]) {
            curr += to_string(1 - (b - '0'));
        }
        a[i] = max(curr, a[i]);
    }

    int ans = 0;
    for (string s : a) {
        ans += stoi(s, nullptr, 2);
    }

    string binary = bitset<64>(ans).to_string();
    return binary.substr(binary.find('1'));
}
int main() {
    int numberofbits = 3; 
    int maximumoperationsallowed = 2;
    vector<string> arr = {"011","100","100"};

    string result = solve(numberofbits, maximumoperationsallowed, arr);
    cout << result << endl;

    return 0;
}
