class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s;
        vector<int> ans;

        unordered_map<int,int>mp;
        for(auto it : nums1) mp[it]++;
        for(auto it : nums2) 
        {
            if(mp.find(it)!=mp.end()) s.insert(it);
        }

        for(auto it : s) ans.push_back(it);

        return ans;
      
    }
};