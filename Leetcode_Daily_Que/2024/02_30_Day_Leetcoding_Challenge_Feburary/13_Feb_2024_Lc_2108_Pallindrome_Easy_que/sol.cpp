// TC=O(n*100)
// SC=O(1)
class Solution {
public:
    bool check(string s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            if((check(words[i]))==true) return words[i];

        }
        return "";
    }
};