/*
Approach : 

1. Our goal is to obtain the minimum number of different Id's after m operations.
2. Try to remove the IDs having less count and in this we will able to get, minimum number of different ID's after m operations., becase the 
bag will contain more number of same items and it will reduce our total different items.
3. Make the array of frequency.
4. sort the new array .
5. start removing the elements from the front till the operations not get 0.
*/


/*

*/

// TC=O(nlogn)
// SC=O(n)
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int n, int op)
{

    sort(arr.begin(), arr.end());
    vector<int> freq;
    // cout<<"arr.size():"<<arr.size()<<endl;
    // for(auto it : arr) cout<<it<<endl;
    // cout<<";"<<endl;
    int cnt = 1;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i - 1] == arr[i])
            cnt++;
        else
        {
            freq.push_back(cnt);
            cnt = 1;
        }
    }

    freq.push_back(cnt);

    sort(freq.begin(), freq.end());
    for (auto it : freq)
        cout << it << endl;
    int ind = 0;
    while (op > 0)
    {

      
        if (freq[ind] <= op)
        {
            op = op - freq[ind];
            freq[ind] = 0;

        // cout<<"ind:"<<ind<<" freq:"<<freq[ind]<<" op:"<<op<<endl;
        }

       
        else  break;
        ind++;
    }

    int ans = 0;
    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i] != 0)
            ans++;
    }
    cout << "ans:" << ans << endl;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********
    //

    //*********

    int n;
    cin >> n;

    int operations;
    cin >> operations;

    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int ans = solve(arr, n, operations);
    cout << ans << endl;

    return 0;
}

/*
input1 :
6
2
1 1 1 2 3 2


Output 1:
freq:
1
2
3
ind:0 freq:0 op:1
ind:1 freq:2 op:-1
ans:2
2




input2 :


Output2:



*/



