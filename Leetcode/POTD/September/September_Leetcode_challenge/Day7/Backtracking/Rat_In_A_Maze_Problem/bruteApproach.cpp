/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1
*/


/*
-> First constraint that , if one path is visited , then u can't visit that path so we need one 
*/


//  Time complexity = O(4^(m*n)) - in each cell of the matrix , we have choice of moving to 4 direction
//  Space Complexity =O(m*n)
class Solution{
    public:
    void solve(int row, int col,vector<vector<int>> &m, int n , vector<string>&ans,vector<vector<int>>& vis, string temp){
       
        
        
        if(row==n-1 && col==n-1){
            ans.push_back(temp);
            return;
        }
        
        //  move down
        if(row+1<n && !vis[row+1][col] && m[row+1][col]==1){
           
            vis[row][col]=1;
            solve(row+1,col,m,n,ans,vis, temp+'D');
             vis[row][col]=0;
        }
        
        //  move up
        if(row-1>=0 && !vis[row-1][col] && m[row-1][col]==1){
          
             vis[row][col]=1;
            solve(row-1,col,m,n,ans,vis,temp+'U');
             vis[row][col]=0;
        }
        
        //  move left
        if(col-1>=0 && !vis[row][col-1] && m[row][col-1]==1){
         
             vis[row][col]=1;
            solve(row,col-1,m,n,ans,vis,temp+'L');
             vis[row][col]=0;
        }
        
        //  move right
        if(col+1<n && !vis[row][col+1]&& m[row][col+1]==1){
           
             vis[row][col]=1;
            solve(row,col+1,m,n,ans,vis, temp+'R');
             vis[row][col]=0;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string temp="";
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0]==1)solve(0,0,m,n,ans,vis,temp);
        return ans;
    }