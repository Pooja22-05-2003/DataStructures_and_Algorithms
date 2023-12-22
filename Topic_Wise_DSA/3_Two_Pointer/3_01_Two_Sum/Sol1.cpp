// Using two pointer 
// TC=O(nlogn)
// SC=O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }


        /*
    index    0   1   2    3
        arr= 2 , 7 , 11 , 15

        v=
        {2->0}
        {7->1}
        {11->2}
        {15->3}

        */


        //  sorting is based on elements
        sort(v.begin(),v.end());


        int i=0;
        int j=nums.size()-1;

        while(i<j){
            int first=v[i].first;
            int second=v[j].first;
            int sum=first+second;

            if(sum==target){
                return {v[i].second , v[j].second};
            }
            else if (sum<target){
                i++;
            }
            else j--;
        }

        return {-1,-1};
    }
};