/*
1. Here we need the maximum sum.
2. so , we try to get maximum value at each index.
3. Index is fixed valud and it is increading. (i)*(arr2[i]-arr1[i]) [Arr2 value try to maximize and arr1 value try to minimize] [And try to put large value of arr2 at least and min value of arr1 at last, so that they will get multiply with large index value].
4. Sort the arr2 in asceding order.
5. Sort the arr1 in desceding order.
6. Then perform the operation and store the ans.

*/
// TC=O(nlogn)
// SC=O(n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int getMaxSumOfArray(vector<int>& arr1, vector<int>& arr2) {
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    reverse(arr1.begin(), arr1.end());  // Corrected line
    long long int total_sum = 0;
    long long int mod = 1000000007;
    for (int i = 0; i < arr1.size(); i++) {
        total_sum = (total_sum % mod + ((i + 1) * (((arr2[i] - arr1[i])%mod)%mod)) % mod) % mod;
    }
    return total_sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    vector<int> arr2(n);
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    cout << getMaxSumOfArray(arr1, arr2) << endl;

    return 0;
}
