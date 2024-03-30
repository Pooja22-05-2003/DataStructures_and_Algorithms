// Recursive sol
// TC=O(2^n)
// SC=O(n*n)

class Solution {
public:
    int solve(int r, int c, int m, int n ,vector<vector<int>>& grid )
    {
        if(r==0 && c==0) return grid[0][0];
        if(r<0 || c<0) return 10000; // here return some large valu, not return 0 value, warna jab bhi out of bound jayega recursion vo best 0 ko leke chalega and valid path ka ans ignore kar dega
        
        int up=grid[r][c]+solve(r-1,c,m,n,grid);
        int left=grid[r][c]+solve(r,c-1,m,n,grid);
        
        return min(up,left);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
    
        return solve(m-1,n-1,m,n,grid);
    }
};