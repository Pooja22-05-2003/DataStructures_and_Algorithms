// Using Bit Manipulation.

// 1. xor of two same numbers is 0. 1^1=0
// 2. xor of a number with 0 is the number itself. 1^0=1
// 3. xor of two different numbers is that numbers xor 1^2=1^2


// TC=O(n)
// SC=O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
       int xorr=0;
        for(auto it : nums) xorr=xorr^it;
        
        for(int i=0;i<=n;i++) xorr=xorr^i;
        
        return xorr;
    }
};