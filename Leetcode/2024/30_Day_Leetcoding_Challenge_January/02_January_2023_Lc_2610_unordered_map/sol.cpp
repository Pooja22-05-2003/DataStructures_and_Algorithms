// TC=O(n)+O(max_freq*size of map)
// SC=O(n)

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
       vector<vector<int>> ans;
       unordered_map<int,int> mp;
       int max_el=0;
       for(int i=0;i<nums.size();i++){
           mp[nums[i]]++;
           max_el=max(max_el,mp[nums[i]]);
       } 
      
       for(int i=0;i<max_el;i++){
        vector<int>temp;

        for(auto it : mp){
              if(it.second>=1) {
                   temp.push_back(it.first);
                   mp[it.first]--;
               }
        }
       ans.push_back(temp);
       }

    return ans;
    }
};
























