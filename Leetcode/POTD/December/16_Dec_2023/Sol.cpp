class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freq;

        // *** edge case
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }

        for(int i=0;i<t.size();i++){
            if(freq.find(t[i])!=freq.end() && freq[t[i]]>0) freq[t[i]]--;
            else return false;
        }

        return true;
    }
};