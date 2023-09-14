/*
Amazon-5
LinkedIn-4
Adobe-3
Facebook-2



There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
 

Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?
*/



// TC=O(logn)
// SC=O(1)
class Solution {
public:
    int search(vector<int>& arr, int target) {
        
        int st=0;
        // **** ⚠️⚠️don't take n as arr.size()-1
        int n=arr.size();
        int end=n-1;

        // *** ⚠️⚠️ if the size of the array is 0 , we cant find any el
        if(n==0) return -1;

        while(st<=end){
            
            int mid=(st+end)/2;
            
            if(arr[mid]==target){
                
                return true;
            }

            //  **** 👀👀 One condition extra here which u need is that if the last element , your mid element and the last element all are eqaul , then shrink your aaray by 2 size st++ and end--
            if(arr[st]==arr[mid] && arr[mid]==arr[end]) {
                st++;
                end--;
            }

            //  **** ⚠️⚠️here it should be greter than equal to
            else if(arr[mid]>=arr[st]){
                //  it was indicating that , left part of the array is sorted

                //  check whether the target lying in the left part or not
                if(arr[st]<=target && arr[mid]>=target){
                    end=mid-1;
                }
                else {
                    st=mid+1;
                }
            }

            else {
                if(arr[mid]<=target && target<=arr[end]){
                    st=mid+1;
                }
                else {
                    end=mid-1;
                }
            }

           
        }

        return false;
    }
};