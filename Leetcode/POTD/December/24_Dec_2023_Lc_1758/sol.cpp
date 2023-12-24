class Solution {
public:
    int minOperations(string s) {
        // we can convert the string in 2 forms
        int start0=0;
        int start1=0;
        // 1. string which start with 0-> means all the odd indexes should be 0
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]=='1') start0++;
            }
            else {
                if(s[i]=='0') start0++;
            }

        }

        // 2. string that start with 1 -> means all the even indexes should be 1
        for(int i=0;i<s.size();i++){
             if(i%2==0){
                if(s[i]=='0') start1++;
            }
            else {
                if(s[i]=='1') start1++;
            }
        }

       
        // return minimum of both as answer
        return min(start0,start1);
    }
};