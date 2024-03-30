// Recursive sol
// TC=O(2^n)
// SC=O(n)

class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>& triangle)
    {
        if(i==n-1) return triangle[i][j];
        // if(i>n || i.size()) return 0; // Not requires, because at the curr index, we are going down or down adajcent, so on the next it will have one more el than the current row, and it will never go out of bound
        
        int down=triangle[i][j]+solve(i+1,j,n,triangle);
        int downRight=triangle[i][j]+solve(i+1,j+1,n,triangle);
        
        return min(down, downRight);
          
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        return solve(0,0,n,triangle);
    }
};