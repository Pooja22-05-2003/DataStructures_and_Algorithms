// TC=On
// SC=O(2n)=O(n)
class Solution {
public:
    bool isvowel(char a){
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<string>mpp;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            int n=s.size();
            if(isvowel(s[0]) && isvowel(s[n-1])) mpp.insert(s);
        }

        vector<int> prefix(words.size(),0);

       if(mpp.find(words[0])!=mpp.end()) prefix[0]=1;
        for(int i=1;i<words.size();i++){
            if(mpp.find(words[i])!=mpp.end()){
                prefix[i]=prefix[i-1]+1;
            }
            else {
                prefix[i]=prefix[i-1];
            }
        }


        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int st=queries[i][0];
            int end=queries[i][1];
            int cnt;
            if(st!=0) cnt=prefix[end]-prefix[st-1];
            else cnt=prefix[end];

            ans.push_back(cnt);
        }
        return ans;
    }
};