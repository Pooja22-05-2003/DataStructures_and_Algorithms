//Approach-2 (Iterate from front and eliminate and then iterate from back and eliminate)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result = "";
        int n = s.length();
        
        //Iterate fron front and eliminate
        int lastOpen = 0;
        for(int i = 0; i<n; i++) {
            char c = s[i];
            if((c >= 'a' && c <= 'z'))
                result.push_back(c);
            else if(c == '(') {
                result.push_back(c);
                lastOpen++;
            } else if(lastOpen > 0) {
                lastOpen--;
                result.push_back(c);
            }
        }
        
        if(result == "")
            return "";
        
        
        s = result;
        result = "";
        int lastClose = 0;
        n = s.length();
        //Iterate fron back and eliminate
        for(int i = n-1; i>=0; i--) {
            char c = s[i];
            if((c >= 'a' && c <= 'z'))
                result.push_back(c);
            else if(c == ')') {
                result.push_back(c);
                lastClose++;
            } else if(lastClose > 0) {
                lastClose--;
                result.push_back(c);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};