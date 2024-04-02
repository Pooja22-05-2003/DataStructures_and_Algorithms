// Recursion
// TC=O(2^n)
// SC=O(n)

class Solution {
public:
    int solve(int ind1, int ind2, string text1 , string text2)
    {
        // base case
        if(ind1<0 || ind2<0) return 0;
    
       
        int take=0;
        if(text1[ind1]==text2[ind2])
        {
            take=1+solve(ind1-1, ind2-1, text1, text2);
        }
        
         // not take 
        int  nottake=max(solve(ind1-1, ind2, text1, text2),solve(ind1, ind2-1, text1, text2));
        
        return max(nottake, take);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        return solve(n1-1, n2-1,text1, text2);
    }
};