// TC=O(n)
// SC=O(n)
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string>m;
        for(int i=0;i<paths.size();i++){
            string start=paths[i][0];
            string end=paths[i][1];
            m[start]=end;
        }

        int i=0;
        string ans=paths[0][0];
        string curr=paths[0][0];
        while(m.find(curr)!=m.end()){
            ans=m[curr];
            curr=ans;
        }

        return ans;
    }
};