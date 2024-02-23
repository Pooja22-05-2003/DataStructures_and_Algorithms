/*
Approach.
1. I thought that this is a easy probelem, just sort the array and take positive numbers and remove all the negative numbers.
2. But if u remove all the negative numbers , this is not correct and not always give the correct answer.
3. Try to take one by one negative number as well , lets say we have -1, then (-1*1) , but now the positive numbers will get the high index. and it will increase the overall answer.
4. So try to take 1 negative number, 2 ,3 and so on and update the maximum regularly.
4. Once u start getting positive ans break the loop and return the final max positive ans.
*/

/*

*/

// TC=O(n2)
// SC=O(1)
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums, int n)
{
    sort(nums.begin(),nums.end());
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(nums[i]<0)
        {
            int sum=0;
            int pk=1;
            for(int j=i;j<n;j++)
            {
                sum=sum+(pk*nums[j]);
                // cout<<"sum:"<<sum<<endl;
                pk++;
               

            }
             ans=max(ans,sum);
        }

        else 
        {
            int sum=0;
            int pk=1;
            for(int j=i;j<n;j++)
            {
                sum=sum+(pk*nums[j]);
                pk++;
                // cout<<"sum:"<<sum<<endl;

            } 
            ans=max(ans,sum);
            break;
        }
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

    vector<int> arr(n, 0);
    for (int i = 0; i <n; i++)
    {
        cin >> arr[i];
    }

  
    int ans = solve(arr, n);
    cout << ans << endl;

    return 0;
}

/*
input1 :
5
-2 5 8 0 1


Output 1:
61


input2 :


Output2:



*/
