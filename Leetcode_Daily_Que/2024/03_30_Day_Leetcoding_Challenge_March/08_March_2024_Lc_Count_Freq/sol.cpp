class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> freq;
        int maxFreq=0;
        for(auto it : nums) 
        {
            freq[it]++;
            maxFreq=max(maxFreq,freq[it]);
        }

        for(auto it : freq)
        {
            if(it.second==maxFreq) ans+=it.second;
        }

        return ans;
    }
};