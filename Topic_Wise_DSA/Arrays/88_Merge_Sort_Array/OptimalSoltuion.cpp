//  Time Complexity = O(logn)
//  Space complexity=O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ind=nums1.size()-1;
        int i=m-1;
        int j=n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[ind]=nums1[i];
                ind--;
                i--;
            }
            else{
                nums1[ind]=nums2[j];
                j--;
                ind--;
            }

        }

        while(i>=0){
            nums1[ind]=nums1[i];
            ind--;
            i--;
        }

        while(j>=0){
            nums1[ind]=nums2[j];
            ind--;
            j--;
        }
    }
};