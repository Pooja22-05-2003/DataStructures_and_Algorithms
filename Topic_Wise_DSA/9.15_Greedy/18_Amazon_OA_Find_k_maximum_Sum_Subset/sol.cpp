/*
Understanding :-> We are giving you an array B -> Find k subsets from this array such that their sum is maximum! 


1.Observation 1 :-> The subset with maximum sum is the sum of all positive elements of the array ; this way we easily find the 1st  ranker

2.Observation 2 :-> But we need the top K rankers -> How to find the second ranker -> Either add the smallest negative number(non-positive-> <=0) to your subset OR remove the smallest positive number from your subset ; subset ->1st ranker 

3.Observation 3 :-> Let's separate the positive and negative elements. Left bucket -> negative elements ; right bucket -> positive elements ; 1st ranker = max_sum = sum of all positive elements; all you can do is select a guy from right bucket and remove or select a guy from left bucket and add it 

4.Observation 4 :-> Hmm.

5.Observation 5 :-> No matter from where you pick up ; sum will only decrease-> so take the absolute value of all the numbers given to you and whoever is the smallest in them:-> 2nd ranker =  you do 1st ranker - smallest number with absolute value; 

6.Question is now :-> Given an array of all >=0 numbers ; find the k smallest subsets. 


*/


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
