// Time Complexity=O(n+q)
// Space Complexity =O(1)

/*
If the range of the element is given then we can use the frequence array and initialize its size with the range
-> Use key as index
-> Use value as element at that index

ex- in this q range is given from 1 to N


==> But lets say range is 10^10 
*** Then we will use inbulit hashmap (Unordered_map,map)

{key , value}

unordered_map<int,int> frequency
map<int,int>f

*/


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