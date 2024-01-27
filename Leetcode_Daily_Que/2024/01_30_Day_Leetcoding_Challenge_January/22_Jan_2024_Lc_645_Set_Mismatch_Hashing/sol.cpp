// TC=O(n)
// SC=O(n)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n+1);
        for(auto it : nums){
            freq[it]++;
        }
        int Duplicate_Num=-1;
        int Single_Num=-1;
        for(int i=1;i<=n;i++){
            if(freq[i]==0) Single_Num=i;
            else if (freq[i]==2) Duplicate_Num=i;
        }
        return {Duplicate_Num,Single_Num};
    }
};