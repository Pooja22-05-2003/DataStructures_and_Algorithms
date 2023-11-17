//  this is not a dp problem as their is no overlapping subproblem

// Use two pointer here 
/*
-> First sort the array
-> Now use for last el , if u want to pair it up to get the sum min, u must pair it with the first el, that would give min among all the possible cases.
-> do this for second last el also
-> So take 2 pointer , one at last and at first and maintain one max sum

*/


// class Solution {
// public:
//     int minPairSum(vector<int>& nums) {
//         sort(nums.begin(),nums.end());

        //  this is not comp- sp this return is wrong 
        /*

        failing on this test case
        
        
Case 1
Case 2
Case 3
Input
nums =
[4,1,5,1,2,5,1,5,5,4]
Output
6
Expected
8
        return (nums[0]+nums[nums.size()-1]);
    }
};

*/



// TC=O(nlogn)
//  space complexity=O(1)    (sorting space-O(logn))
/*
In C++ std::sort() function provided by STL is a hybrid of Quick Sort, Heap Sort, and Insertion Sort and has a worst-case space complexity of O(log⁡N)O(\log N)O(logN). Thus, the use of the inbuilt sort() function might add up to O(log⁡N)O(\log N)O(logN) to space complexity.

*/
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int st=0;
        int end=nums.size()-1;
        int ans=0;
        while(st<end){
            int sum=nums[st]+nums[end];
            ans=max(ans,sum);
            st++;
            end--;
        }
        return ans;
    }
};