// TC=O(n*m)*O(n+m)==O(n^3)
// SC=O(n+m)
class Solution{
    public:
    int helper(string &S1, string &S2, int i, int j){
        if(i<0 || j<0) return 0;
        int take=0;
        int nottake=0;
        if(S1[i]==S2[j]){
            take= 1+helper(S1,S2,i-1,j-1);
        }
        else {
            nottake=0;
        }
        return max(take,nottake);
         
        
    }
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {

       int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                ans=max(ans,helper(s1,s2,i,j));
            }
        }
       return ans;
    }
};
