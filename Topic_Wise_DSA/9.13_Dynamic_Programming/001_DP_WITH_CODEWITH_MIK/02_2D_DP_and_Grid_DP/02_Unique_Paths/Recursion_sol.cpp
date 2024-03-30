// Recursive Sol
// TC=O(2^n)
// SC=O(n)

class Solution {
public:
    int solve(int r, int c, int m, int n)
    {
        // base case
        if(r==m-1 && c==n-1) return 1;
        if(r>=m || c>=n) return 0;
        
        int ans1=solve(r,c+1,m,n);
        int ans2=solve(r+1,c,m,n);

        return ans1+ans2;
    }
    int uniquePaths(int m, int n) {
        return solve(0,0,m,n);
    }
};