//  Dutch National Flag Algorithm

//  Time Complexity =O(N)
//  Space Complexity =O(1)

/*

Dive the whole array in 4 sections, one will conatain 0's, another will contain 1's then third part will be unsorted, and 4th part will contain 2's


0 ---low-1,  low---mid-1,    mid---high,    high+1---n-1
0,0,0,0,      1,1,1,1,1      unsorted part    2,2,2,2,2



2,0,2,1,1,0 ( Here in our algorithm from low to high our array is unsorted)
low       high
mid    


*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;


        //  *** Here u need to move from mid to high , so equal to is needed
        while(mid<=high)
        {
           if(nums[mid]==0)
           {
               swap(nums[low],nums[mid]);
               low++;
            //    because we are swapping with one , so we need to move mid to unsorted part, so do mid++
               mid++;
           } 
           else if(nums[mid]==1)
           {
               mid++;
           }

           else if (nums[mid]==2) 
           {
               swap(nums[mid],nums[high]);
               high--;

           }
        }
    }
};








