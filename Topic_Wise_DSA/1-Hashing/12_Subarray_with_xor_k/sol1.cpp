#include <bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int k) {
    // Write your code here
    unordered_map<int,int> mp;
    int currXOR=0;
    int ans=0;
    for(int i=0;i<a.size();i++){
        currXOR^=a[i];
        if(currXOR==k) ans++;
        if(mp.find(currXOR^k)!=mp.end()) ans+=mp[currXOR^k];
        mp[currXOR]++;
       
    }
    return ans;
}