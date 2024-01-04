//  Time Complexity =O(nlogn)
//  Space Complexity =O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            //  Push the current interval in the answer if the ans vector is empty, or the current element first index is greater then the last pushed element in the answer vector
            if(ans.empty() || ans.back()[1] <intervals[i][0]){
                ans.push_back(intervals[i]);
            }

            else 
            {
                ans.back()[1]=max(ans.back()[1] , intervals[i][1]);
            }

        }

        return ans;
    }
};