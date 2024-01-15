
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // mp1 represent all the players that are plyaed in the match

        unordered_map<int,int>mp1;
        for(int i=0;i<matches.size();i++){
            int el1=matches[i][0];
            int el2=matches[i][1];
            if(mp1.find(el1)==mp1.end()) mp1[el1]++;
            if(mp1.find(el2)==mp1.end()) mp1[el2]++;
        }

      
        unordered_map<int,int> loosers;
        for(int i=0;i<matches.size();i++){
            int el1=matches[i][0];
            int el2=matches[i][1];
            loosers[el2]++;
        }

        vector<vector<int>> ans;
        vector<int> v1;
        vector<int> v2;

        for(auto it : loosers){
            int freq=it.second;
            int element=it.first;
            if(freq==1) v2.push_back(element);
        }

        // players who never losed any matches
        for(auto it : mp1){
            int el=it.first;
            if(loosers.find(el)==loosers.end()) v1.push_back(el);
        }

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        ans.push_back(v1);
        ans.push_back(v2);


        return ans;
    }       
};