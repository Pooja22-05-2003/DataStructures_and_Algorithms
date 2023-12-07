/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

// TC=O(logn)
//  SC=O(1)
class Solution {
public:
    int FirstOccurence(vector<int>& arr,int target){
        int ans=-1;
        int st=0;
        int end=arr.size()-1;

        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]==target){
                ans=mid;
                end=mid-1;
            }
            else if(arr[mid]>target){
                
                end=mid-1;
            }

            else {
                st=mid+1;
            }
        }

        return ans;
    }

    int LastOccurence(vector<int>& arr,int target){
        int ans=-1;
        int st=0;
        int end=arr.size()-1;

        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]==target){
                ans=mid;
                st=mid+1;
                
            }

            // ⚠️⚠️⚠️😶‍🌫️😶‍🌫️ here u wrote the opposite sign for this
            else if(arr[mid]<target){
                st=mid+1;
            }

            else {
               end=mid-1;
            }
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans1=FirstOccurence(nums,target);
        int ans2=LastOccurence(nums,target);
        vector<int> ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};