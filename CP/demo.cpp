#include <bits/stdc++.h>
using namespace std;

int main()
{

    //**********

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //*********

    int n, q;
    cin >> n >> q;
    int arr[n + 1];
    unordered_map<int, int> frequency;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
          frequency[arr[i]]=frequency[arr[i]]+1;
    }
   

    while (q > 0)
    {
        int x;
        cin >> x;
        cout << frequency[x]<<endl;
        q--;
    }
}