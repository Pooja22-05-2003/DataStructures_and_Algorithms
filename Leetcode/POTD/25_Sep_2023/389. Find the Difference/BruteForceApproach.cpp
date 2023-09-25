//  Time Complexity=O(2*n)
//  Space Complexity=O(n)
class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int>mp;
        for(auto it : t){
            mp[it]++;
        }

        for(auto it:s){
            mp[it]--;
        }
        
        for(auto it:mp){
            if(it.second>0) return it.first;
        }

        return ' ';
    }
};