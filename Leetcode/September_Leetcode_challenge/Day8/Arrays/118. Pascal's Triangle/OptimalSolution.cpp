// ✨✨✨✨
// 1. Given row and col number , find the element in pascals triangle.

/*
Time Complexity: O(n*n*r) ~ O(n3), where n = number of rows, and r = column index.
Reason: The row loop will run for approximately n times. And generating a row using the naive approach of variation 2 takes O(n*r) time complexity.

Space Complexity: In this case, we are only using space to store the answer. That is why space complexity can be still considered as O(1).
*/



#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}
