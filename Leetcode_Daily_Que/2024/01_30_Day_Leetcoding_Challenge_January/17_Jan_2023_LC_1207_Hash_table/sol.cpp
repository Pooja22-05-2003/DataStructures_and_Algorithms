class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<arr.size();i++){
          
                mp[arr[i]]++;
            
        }

        vector<int>v;
        for(auto it : mp){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        int i=0;
        while(i<v.size()-1){
            if(v[i]==v[i+1]) return false;
            i++;
        }
        return true;
    }
};