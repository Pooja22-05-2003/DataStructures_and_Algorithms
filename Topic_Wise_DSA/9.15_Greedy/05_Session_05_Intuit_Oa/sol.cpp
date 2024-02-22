/*
1. Create one vector , which store both the primary and secondary
skill of the ith student.
2. Sort the array. (Now we have the sorted array acoording to the first skill).
3. Now for any index i, we know all the element from 0 to i-1 will have primary skill less than current one. and all the 
elememt from i+1 to n , will have primary skill greater than the current one. (Let's now ignore the same ele), we will handle it later on.
4.Now iterate from back. For index i to pass the exam, no element from index i-1 to 1 will able to defeat this.
For passing it, all the element from i+1 to n have greater primary skill. But if from index i+1 to n, no one will have greater secondary skill, then it will win.(Becasue now no elemetn is there who have both primary and secondary skill higher).
5.Now for same element. 
Let's say 2 elemets are same.

index
0 1 2 3 4
5
1 2 2 2 5 
5 
5 4 3 2 1 

SAME ELEMENTS CASE:
For index 2, index 3 is same , so it do not have greater primary skill, it will never able to defeat index el 2.
For winning index element 2, it should compare with index 4(secondary value). (If that element do not have greater secondary value than 2). Then it will win.

*/

/*

*/

// TC=O(nlogn)
// SC=O(n)
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, vector<int> arr1, int n)
{
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++)
    {
        int first = arr[i];
        int second = arr1[i];
        v.push_back({first, second});
    }

    sort(v.begin(), v.end());

    vector<int> suffix(n + 1, 0);
    int temp = 0;
    for (int i = n-1; i >=0; i--)
    {
        int x = v[i].second;
        temp = max(temp, x);
        suffix[i] = temp;
        cout<<"i:"<<i<<" ,"<<"suffix[i]:"<<suffix[i]<<endl;
    }

    int ans=1;
    int i = n - 2;
    int ind=n;
    while (i >= 0)
    {
        int f=v[i].first;
        int s=v[i].second;

        if(f==v[i+1].first)
        {
            // ind will not update
        }
        else ind=i+1;

        if(s<suffix[ind])
        {
            // not valid
        }
        else ans++;

        i--;
    }

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

    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int n1;
    cin >> n1;

    vector<int> arr2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr2[i];
    }

    int ans = solve(arr, arr2, n);
    cout << ans << endl;

    return 0;
}

/*
input1 :
3
1 2 3
3
3 2 1


Output 1:
3


input2 :
2
1 2
2
2 3

Output2:
1


*/
