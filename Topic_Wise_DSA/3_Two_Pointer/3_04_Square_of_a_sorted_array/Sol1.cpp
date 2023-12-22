// TC=O(n)
// Sc=O(1)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int k=nums.size()-1;

        vector<int> ans(nums.size());


        //  must move number from while(i<=j)
        while(i<=j){
            int ElSquare1=nums[i]*nums[i];
            int ElSquare2=nums[j]*nums[j];
            
            if(ElSquare1>ElSquare2){
                ans[k]=ElSquare1;
                k--;
                i++;
            }
            else {
               ans[k]=ElSquare2;
                k--;
                j--; 
            }
        }

        return ans;
    }
};