// TC=O(nlogn)
// SC=O(n)
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        if(n1!=n2) return false;
        else {
            vector<int> s1;
            vector<int>s2;

            vector<int> v2;

            unordered_map<char,int> mp1;
            unordered_map<char,int> mp2;
            for(int i=0;i<word1.size();i++){
                mp1[word1[i]]++;
            }

            for(int i=0;i<word2.size();i++){
                mp2[word2[i]]++;
            }

            for(auto it:mp1) 
            {
                if(mp2.find(it.first)==mp2.end()) return false;
                s1.push_back(it.second);
            }
            for(auto it:mp2)
            {
               
                s2.push_back(it.second);
            } 

            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());

            for(int i=0;i<s1.size();i++) if(s1[i]!=s2[i]) return false;
            
        }

        return true;
    }
};