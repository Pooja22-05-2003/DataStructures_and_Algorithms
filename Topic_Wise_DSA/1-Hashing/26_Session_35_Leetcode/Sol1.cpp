// Time Complexity  - O(nlogn) // map store element in the ordered fashion , so take O(nlogn) time complexity.


// Space Complexity - O(N) // for the map
/*
-> Using map -> store the all elements frequency
-> Find the maximum value stored corresponding to any element in the map.
-> created 2D vector of that many rows. - because we can't place 2 same element in the same row.
-> Now iterate through map, and store the elements column wise
*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mp;
        int maxx=INT_MIN;=
        for(auto it : nums){
            mp[it]++;
            maxx=max(maxx , mp[it]);
        }

        int max_row=maxx;
        vector<vector<int>> arr(max_row);

        for(auto it : mp){
            int i=0;
            int j=it.second;
            while(i<j){
                // Pushing elements in column wise
                arr[i].push_back(it.first);
                i++;
            }
        }
        return arr;
    }
};






















