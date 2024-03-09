class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1;
        map<int,int>mp2;

        for(auto it: nums1) mp1[it]++;
        for(auto it : nums2) mp2[it]++;

        for(auto it : mp1) if(mp2.find(it.first)!=mp2.end()) return it.first;

        return -1;

    }
};