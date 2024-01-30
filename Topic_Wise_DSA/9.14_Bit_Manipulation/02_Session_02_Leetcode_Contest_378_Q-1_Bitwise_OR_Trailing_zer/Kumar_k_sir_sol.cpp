/*
1. Even numbers last bit is 0.
2. BitWise OR of two even number has trailing zero.
3. So , the que is reduced to count whether the array has more than or equal to 2 even numbers.

*/
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt=0;
        for(auto it : nums)
        {
            if((it & 1)==0) cnt++;
        }
        return cnt>=2;
    }
};