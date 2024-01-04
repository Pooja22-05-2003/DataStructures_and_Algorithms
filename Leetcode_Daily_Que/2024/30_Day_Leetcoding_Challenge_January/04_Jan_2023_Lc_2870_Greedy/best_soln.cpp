/*
Approach :
1. If n=1 , ans=-1;
n=2, ans =1;
n=3, ans=1 => ans=ceil(n/3) 
n=4, ans=2 => ceil (4/3)=> 2
n=5, ans=2
n=6, ans=2
n=7, ans=3
...n=10^5
*/

// TC=O(N)
// SC=O(N)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto it : nums){
           freq[it]++;
        }
        int ans=0;
        for(auto it : freq){
            int cnt=it.second;
            if(cnt==1) return -1;
            else {
                ans+=ceil(double(cnt)/3);
            }   
        }

        return ans;
    }
};