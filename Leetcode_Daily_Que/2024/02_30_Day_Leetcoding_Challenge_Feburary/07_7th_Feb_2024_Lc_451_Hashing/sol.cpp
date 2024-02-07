// TC=O(nlogn)
// sC=O(n)
class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto x : s) mp[x]++;

        vector<pair<int,char>>v;

        for(auto it:mp)
        {
            v.push_back({it.second,it.first});
        }

        sort(v.begin(),v.end() , greater<pair<int,char>>());

        string ans="";

        for(auto it : v)
        {
            while(it.first--) ans+=it.second;
        }   
        return ans;

    }
};