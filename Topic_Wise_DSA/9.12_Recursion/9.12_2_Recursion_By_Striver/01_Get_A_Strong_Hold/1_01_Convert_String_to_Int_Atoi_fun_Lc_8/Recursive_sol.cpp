// TC=O(n), n=s.size()
// SC=O(n)
class Solution {
public:
    int solve(string s, int sign, int i, long long res){
    
        if(sign*res>=INT_MAX) return INT_MAX;
        if(sign*res<=INT_MIN) return INT_MIN;

        // If after any numeric number ....... any decimal(.) or gap(' ') or any digit come, then return the numerica answer till that there only
        if(s[i]==' ' || !isdigit(s[i])) return res*sign;
        int sol=s[i]-'0';
        return solve(s,sign,i+1,res*10+sol); 
    }
    int myAtoi(string s) {
        int flag=0;
        int sign=1;
        int i=0;
        //  all the empty initial empty spaces are handled here only
        while(i<s.size() && s[i]==' ') i++;

        if(s[i]=='-'){
            sign=-1;
            i++;
            flag++;
        }
        if(s[i]=='+'){
            sign=1;
            i++;
            flag++;
        }
       
        if(flag>1) return 0;
        return solve(s,sign,i,0);
    }
};