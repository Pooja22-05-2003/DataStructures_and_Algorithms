class Solution {
public:
    int solve(int i, int j, int m , int n , vector<vector<int>>& nums)
    {
        if(i==m-1) return nums[i][j];
        if(i>m || j>n) return 1000000;
        
        int below, Dleft, Dright=10000000;
        if(i+1<m  ) below=nums[i][j]+solve(i+1,j,m,n,nums);
        if(i+1<m && j-1>=0) Dleft=nums[i][j]+solve(i+1, j-1, m , n, nums);
        if(i+1<m && j+1<n) Dright=nums[i][j]+solve(i+1,j+1,m,n,nums);
            
        return min(below, min(Dleft, Dright));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int j=0;j<n;j++)
        {
            ans=min(ans,solve(0,j,m,n,matrix));
        }
        return ans;
    }
};