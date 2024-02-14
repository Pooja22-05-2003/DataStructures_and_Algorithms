/*
1. Arr given -> Of Even length (Containn Positive no==negative no(In count)).
2. Rearrang arr-> Such that
  -> Consecutive pair of el have opp sign.
  -> All the element of same sign order must be preserved after rearranging the arr.
  -> rearranged must arr must start with the positive integer.
  -> Return the final Modified arr.

*/


/*
We can use the extra array to solve this question.

*/

//TC=O(N)
//SC=O(N)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
       vector<int>ans(n,0);
        
       int posIndex=0;
        int negIndex=1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                ans[posIndex]=nums[i];
                posIndex+=2;
            }
            else 
            {
                ans[negIndex]=nums[i];
                negIndex+=2; 
            }
        }
        
        return ans;
        
    }
};