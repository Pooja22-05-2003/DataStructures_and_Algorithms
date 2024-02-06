// TC=O(n)
// SC=O(n)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;

        for(auto it : strs)
        {
            string s=it;
            sort(s.begin(),s.end());

            mp[s].push_back(it);
        }

        vector<vector<string>> ans;
        for(auto it : mp)
        {
            auto first=it.first;
            vector<string>temp;
            for(auto x: mp[first])
            {  
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;


    }
};