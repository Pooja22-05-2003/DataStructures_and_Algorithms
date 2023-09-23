/*

The given code solves the N-Queens problem using backtracking. The time complexity of this code is exponential, specifically O(N!), and the space complexity is O(N^2).

Let's break it down:

Time Complexity: The code uses a recursive approach to find all possible solutions to the N-Queens problem. In the worst case, it explores all possible combinations of queen placements in each row and column. For each column (from 0 to N-1), it iterates through all possible rows (from 0 to N-1) to place a queen, and for each queen placement, it recursively explores the next column. This results in a tree of recursive calls with N levels, and at each level, it explores N possibilities. Therefore, the time complexity is O(N * N!).

Space Complexity: The space complexity mainly arises from the memory used to store the chessboard configuration. The code maintains a 2D board vector of size N x N to represent the chessboard, which results in O(N^2) space complexity. Additionally, it uses three vectors (leftRow, upperDiagonal, and lowerDiagonal) of size N and 2N-1 each, resulting in a total space complexity of O(N + 2N-1 + 2N-1) = O(N).

So, in summary:

Time Complexity: O(N * N!)
Space Complexity: O(N^2)
The time complexity is exponential because the number of possible solutions grows factorially with N, making it impractical for large values of N.







*/



class Solution {
public:
  
    void solve(int col,vector<string>& board,vector<vector<string>>&ans, int n ,vector<int>&leftRow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal ){
        //  base case 
        if(col==n){
            ans.push_back(board);
            return ;
        }


        //  For placing n queens in n columns , we are running three n loop for placing in 1 col
        for(int row=0;row<n;row++){
            // if(isSafe(row,col,board,n)){
            //     board[row][col]='Q';
            //     solve(col+1,board,ans,n);
            //     //  backtrack to explore all the possible soltuions
            //     board[row][col]='.';
            // }

             if(leftRow[row]==0 && upperDiagonal[n-1+col-row]==0 &&lowerDiagonal[row+col]==0){
                
                board[row][col]='Q';
                  leftRow[row] = 1;
                  lowerDiagonal[row + col] = 1;
                  upperDiagonal[n - 1 + col - row] = 1;
                solve(col+1,board,ans,n,leftRow,upperDiagonal,lowerDiagonal);
                //  backtrack to explore all the possible soltuions
                board[row][col]='.';
                  leftRow[row] = 0;
                  lowerDiagonal[row + col] = 0;
                  upperDiagonal[n - 1 + col - row] = 0;
                
            }

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        //  Created n*n matrix having all the empty character 
        vector<string>board(n);

        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }

        //  create three vectors(Hash array)
        vector<int>leftRow(n,0);
        vector<int> upperDiagonal(2*n-1,0);
        vector<int> lowerDiagonal(2*n-1,0);


        solve(0,board,ans,n,leftRow,upperDiagonal,lowerDiagonal);
        return ans;

    }
};




