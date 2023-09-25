// ✨✨✨✨

// Brute Force Approach-2
/*
1. Traverse the matrix and if u are finding any box to be 0 , then mark its corresponding row to -1 and its corresposding column to -1 ( Traversing will take O(n*m) and for each u are marking corresponding row and col to -1 , total - O(n*m)*O(n+m))

2. Again traverse the whole matrix , mark the -1 to 0

*/


//  Time Complexity=O(n*m)*O(n+m)
//  Space complexity=O(1)

class Solution {
public:

    void MarkRow(vector<vector<int>>& matrix,int row){
        //  for marking that whole row to 0 , iterate to its all col
        int m=matrix[0].size();
        for(int i=0;i<m;i++){
            if(matrix[row][i]!=0) matrix[row][i]=-1;
        }
    }

    void MarkCol(vector<vector<int>>& matrix , int col){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            if(matrix[i][col]!=0) matrix[i][col]=-1;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    MarkRow(matrix,i);
                    MarkCol(matrix,j);
                }
            }
        }



         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};