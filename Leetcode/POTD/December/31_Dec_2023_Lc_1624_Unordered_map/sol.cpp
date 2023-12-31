class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
    
        int ans=-1;
        unordered_map<char,int> mp;
        int i=0;
        int n=s.size();
        while(i<n){
            if(mp.find(s[i])!=mp.end()) ans=max (ans,((i-(mp[s[i]])+1)-2));
            else mp[s[i]]=i;
            i++;
        }

        return ans;
    }
};