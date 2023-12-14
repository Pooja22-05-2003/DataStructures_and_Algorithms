// TC=O(m*n)
// SC=O(n)

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rowSize=grid.size();
        int colSize=grid[0].size();

        vector<int>rowCount_Zero(rowSize,0);
        vector<int>rowCount_One(rowSize,0); 
        vector<int>ColCount_Zero(colSize,0);
        vector<int>ColCount_One(colSize,0); 

        for(int i=0;i<rowSize;i++){
            int zeroCnt=0;
            int oneCnt=0;
            for(int j=0;j<colSize;j++){
                if(grid[i][j]==0) zeroCnt++;
                else oneCnt++;
            }   
            rowCount_Zero[i]=zeroCnt;
            rowCount_One[i]=oneCnt;
        }

         for(int i=0;i<colSize;i++){
            int zeroCnt=0;
            int oneCnt=0;
            for(int j=0;j<rowSize;j++){
                if(grid[j][i]==0) zeroCnt++;
                else oneCnt++;
            }   
            ColCount_Zero[i]=zeroCnt;
            ColCount_One[i]=oneCnt;
        }

        vector<vector<int>> ans(rowSize , (vector<int> (colSize,0)));

        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                int zeroRow_i=rowCount_Zero[i];
                int onesRow_i=rowCount_One[i];
                int zerosCol=ColCount_Zero[j];
                int onesCol=ColCount_One[j];
                ans[i][j]=onesRow_i+onesCol-zeroRow_i-zerosCol;
                
            }
        }

        return ans;
    }
};










