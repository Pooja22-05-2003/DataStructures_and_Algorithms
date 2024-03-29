// TC=O(Nlogn+OOklogk)
// SC=O(k) // k is the subsetsum arr
#include <bits/stdc++.h>
using namespace std;
void findSubset(vector<int>&SmallestEl,vector<int>&subsetSum , int limit)
{

    for(int i=0;i<(1<<limit);i++)
    {
        int sum=0;
        for(int j=0;j<limit;j++)
        {
            //  i ka jth bit set hai ya nahi
            if(1& (i>>j)) sum+=SmallestEl[j];
        }

        subsetSum.push_back(sum);
    }

}

void solve(vector<int> arr, int n, int k)
{
  
    int postELSum=0;
    vector<int>v;
    for(auto it : arr)
    {
        if(it>0) postELSum+=it;
        v.push_back(abs(it));
        
    }
    sort(v.begin(),v.end());

    // maximum range of k is 2000 (2^11 is 2048 ), so 11 numbers can easily generate 2000 subsets.
    // Now when u divide the negtaive and positive ele, and start picking the smallest pos number and smallest negative number , then subset sum will always be decrease.
    // So, it don't matter u are picking negative or positive number, so make the -ve number also to positive number.

    // put smallest v element in the new array and try to generate 2^11 subset and put the sum in the new arr
    int limit=min(n,11);

    vector<int>SmallestEl;
    int i=0;
    while(i<limit)
    {
        SmallestEl.push_back(v[i]);
        i++;
    }

    vector<int>subsetSum;
    // find the k subset sum of smaleest el
    findSubset(SmallestEl,subsetSum,limit);

    sort(subsetSum.begin(),subsetSum.end());

    i=0;
    while(i<k)
    {
        cout<<postELSum-subsetSum[i]<<" ";
        i++;
    }
    cout<<endl;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********
    int n;
    cin >> n;
    int k;
    cin>>k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(arr, n,k);
    // cout << "ans:" << ans << endl;
    // cout << (2 | 5) << " ," << (2 | 8) << " ," << (5 | 8) << " ," << (2 | 5 | 8) << endl;
    return 0;
}

/*
input1 :
3
3
3 5 -2

Output 1:
8 6 5 


input1 :


Output 1:






*/
