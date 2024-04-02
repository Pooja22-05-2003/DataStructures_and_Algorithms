/*

// After seeing the striver video.
1. Got to know that we can solve this problem using Longest common subsequence.
2. create one copy of the original string., reverse this.
3. Then return the lcs code.


*/

// Space Optimization=> ✨✨Do the right shift in the tabulation
// TC=O(len1*len2)
// SC=O(len2)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<int>prev(n2+1,0);
        vector<int>curr(n2+1,0);
        
        
        // right shift by 1 index
       
        
        for(int ind1=1;ind1<=n1;ind1++)
        {
            for(int ind2=1;ind2<=n2;ind2++)
            {
                 int take=0;
                 if(text1[ind1-1]==text2[ind2-1])  // index-1 we are doing , becuase we considered the right shift
                 {
                     take=1+prev[ind2-1];
                 }
        
                 // not take 
                 int  nottake=max(prev[ind2],curr[ ind2-1] );
        
                 curr[ind2]=max(nottake, take);
            }
            prev=curr;
        }
            
        return prev[n2];
    }
   
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t);
    }
};