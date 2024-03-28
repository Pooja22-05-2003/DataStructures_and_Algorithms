/*
Approach:
1. Sliding Window + Sorting will work here.
2. We can easily do this que using brute force by checking all the subarray.
3. But , for subset of size k, wee need to find the maximum and minimum value, so fix one pointer lets say i which
iterate through all the indexes, for every index i, go p step ahead and find the diff, and update the mindiff value.

*/

// TC=O(nlogn)
// SC=O(1)

#include <bits/stdc++.h>
using namespace std;
int main()
{
   vector<int> v={3,4,1,9,56,7,9,12,13};int p=5;
   
   sort(v.begin(),v.end());
   int ans=INT_MAX;
   
   for(int i=0;i<=v.size()-p;i++)
   {
    ans=min(ans,v[i+p-1]-v[i]);    
   }
    cout<<ans;
return 0;
}