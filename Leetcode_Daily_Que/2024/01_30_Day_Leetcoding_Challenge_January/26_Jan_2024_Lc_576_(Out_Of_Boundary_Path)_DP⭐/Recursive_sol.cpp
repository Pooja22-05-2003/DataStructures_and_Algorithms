// Time Complexity=O(4^n)
// Space Complexity=O(n)
class Solution {
public:
    int mod=1e9+7;
    int solve(int r,int c,int currMove,int m,int n,int maxMove)
    {
        // grid indexing start from 0 and go till n-1 or m-1
        if(r<0 || r>=m || c<0 || c>=n) return 1;
        if(currMove==maxMove) return 0;
        // 4 options at curr position
      
        int up=(solve(r-1,c,currMove+1,m,n,maxMove))%mod;
        int down=(solve(r+1,c,currMove+1,m,n,maxMove))%mod;
        int left=(solve(r,c-1,currMove+1,m,n,maxMove))%mod;
        int right=(solve(r,c+1,currMove+1,m,n,maxMove))%mod;

        return (up+down+left+right)%mod;

    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return solve(startRow,startColumn,0,m,n,maxMove);
    }
};