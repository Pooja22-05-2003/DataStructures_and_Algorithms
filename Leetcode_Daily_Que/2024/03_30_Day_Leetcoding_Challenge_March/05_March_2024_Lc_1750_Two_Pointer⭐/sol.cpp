// TC=O(n)
class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j=s.size()-1;

        // if character at first and last index are not same, then its answer would always be strign lenght, because we were never able to delete the first and the last character
        // ex-zcabaabacm ; ans=10
        while(i<j && (s[i]==s[j]))
        {
            char currChar=s[i];

            while(s[i]==currChar && (i<=j)) i++;
            while(s[j]==currChar && (j>=i)) j--;
        }

        return (j-i)+1;
    }
};