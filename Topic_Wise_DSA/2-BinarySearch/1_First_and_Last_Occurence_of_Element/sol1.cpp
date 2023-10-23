// Using Binary Search 
// TC=O(nlogn)
// SC=O(1)

class Solution {
public:
    int FirstOccurence(vector<int>& nums, int target){
        int FirstIndex=-1;
        int st=0;
        int end=nums.size()-1;
        while(st<=end){
            int mid=(st+end)/2;
            cout<<"mid:"<<mid<<endl;
            if(nums[mid]==target){
                FirstIndex=mid;
                end=mid-1;
            }
            else if (nums[mid]>target){
                end=mid-1;
            }
            else {
                st=mid+1;
            }
        }

        return FirstIndex;
    }

    int LastOccurence(vector<int>& nums, int target){
        int Lastindex=-1;
        int st=0;
        int end=nums.size()-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(nums[mid]==target){
                Lastindex=mid;
                st=mid+1;
            }
            else if (nums[mid]>target){
                end=mid-1;
            }
            else {
                st=mid+1;
            }
        }

        return Lastindex;
    }

    
    vector<int> searchRange(vector<int>& nums, int target) {
        int FirstIndex=FirstOccurence(nums,target);
        int Lastindex =LastOccurence(nums,target);
        return {FirstIndex , Lastindex};
    }
};





