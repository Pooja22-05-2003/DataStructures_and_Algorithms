class Solution {
public:
    int maxDepth(string s) {
        int maxdepth=0;
        int cnt=0;
        int openBracketCnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') 
            {
                openBracketCnt++;
                maxdepth=max(maxdepth,openBracketCnt);
            }
            else if (s[i]==')') openBracketCnt--;
        }
        return maxdepth;
    }
};