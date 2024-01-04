//  Exponential Time Complexity = O(N!*N) 
//  Space Complexity=O(N^2)



class Solution {
public:
    bool isSafe(int row, int col,vector<string>& board,int n){
        int r=row;
        int c=col;
        //  check whether the element is row wise and col wise sorted (Upper diagonal safe)     
         while(row>=0 && col>=0){
             if(board[row][col]=='Q') return false;
             row--;
             col--;
         }


        //  chech whether the element is row wise (safe )
        row=r;
        col=c;
         while(col>=0){
             if(board[row][col]=='Q') return false;
            //  row--;
             col--;
         }

        //  check whether the element is row wise and column wise (lower diagonal safe)
        row=r;
        col=c;
         while(row<n && col>=0){
             if(board[row][col]=='Q') return false;
             row++;
             col--;
         }

         return true;
    }

    void solve(int col,vector<string>& board,vector<vector<string>>&ans, int n  ){
        //  base case 
        if(col==n){
            ans.push_back(board);
            return ;
        }


        //  For placing n queens in n columns , we are running three n loop for placing in 1 col
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                //  backtrack to explore all the possible soltuions
                board[row][col]='.';
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
        solve(0,board,ans,n);
        return ans;

    }
};