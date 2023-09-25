//  Brute Force approach 
//  Time Complexity=O(n*n*n)
//  Space Complexity=O(n*n)
class Solution {
public:
    void setZero(vector<vector<int>>& matrix,int row, int col){
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            matrix[i][col]=0;
           
        }

        for(int i=0;i<m;i++){
            matrix[row][i]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> temp(n,vector<int>(m,0));
        temp=matrix;
        //  iterate on temp and find the boxes having 0, set in temp matrix, the ith and jth col row corresponding to that matrix as 0

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]==0){
                    setZero(matrix,i,j);
                }
            }
        }
    }
};