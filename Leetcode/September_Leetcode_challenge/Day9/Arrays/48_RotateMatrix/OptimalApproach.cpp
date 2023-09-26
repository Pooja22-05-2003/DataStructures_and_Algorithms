//  Time Complexity=O(n*m)
//  Space Complexity=O(1)
/*
-> First do transpose of the whole matrix.
-> Then do the reverse of each row
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        for(int i=0;i<row;i++){
            for(int j=i;j<col;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }


        //  Reverse each row indvidually
        for(int i=0;i<row;i++)
        {
            reverse(matrix[i].begin() , matrix[i].end());
        }
    }
};



