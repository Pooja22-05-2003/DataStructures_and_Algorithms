// Binary Search , TC= O(n*logn). SC=O(n)[ Temp vector we are using]

// Remeber that , temp is the longest subsequence, and it was not containing that element.
// but it can tell the exact longest increasing subsequence lenght
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        
        // put the first el in the vector
        temp.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()) temp.push_back(nums[i]);
            else {
                // lower_bound function is an iterator, that return the first just greater element index then nums[i], and if u want that index, u need to subtract the starting position of the arr.
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }

        return temp.size();
    }
};