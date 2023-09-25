/*✨✨✨✨
Optimal Approach- Hashing(using the first row and col as hash array)
-> Do the matrix traversal:
-> If any column contain 0 then corresponding to that column matrix (use first row (except 0th col- for that take another variavle col0)to for hasing for column matrix)mark it to 1
-> If any row contain 0, then correspoding to that row matrix (use first col for hasing to all rows)mark it to 1
->Now again do the whole matrix traversal, if u are finding any correspong to any iand j , if any one of the hash array contain 1, mark it to 0

*/


//  Time Complexity=O(2*(n*m))
//  Space Complexity=O(1) [ In place ]
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        // vector<int> RowHashing(n,0);
        // vector<int> ColHasing(m,0);
        int col0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    //  row hashing
                    matrix[i][0]=0;
                    if(j==0){
                        col0=0;
                    }
                    else {
                    matrix[0][j]=0;
                    }
                }
            }
        }


        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(RowHashing[i]==1 || ColHasing[j]==1) matrix[i][j]=0;
        //     }
        // }

        //  here 2nd traversal would be somehow different
        for(int i=n-1;i>0;i--){
            for(int j=m-1;j>0;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0 ) matrix[i][j]=0;
                // if(matrix[0][j]==0) matrix[i][j]=0;
            }
        }


    //     if row0 has even one 0 then mark whole row0 as 0 starting from first index, and use col0 for 0 th index checking



    if(matrix[0][0]==0){
        //  it mean we need to set whole 0th row as 0
        for(int i=0;i<m;i++){
            matrix[0][i]=0;
        }
    }

    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }

// ❌❌ this is wrong 

    // bool row0=false;
    // for(int i=1;i<n;i++){
    //     if(matrix[0][i]==0 || col0==0) row0=true;
    // }


    // bool Col0=false;
    // for(int i=0;i<m;i++){
    //     if(matrix[i][0]==0 ) Col0=true;
    // }

    // if(row0==true){
    //     for(int i=0;i<n;i++){
    //     matrix[0][i]=0;
    // }
    // }

    // if(Col0==true){
    //     for(int i=0;i<m;i++){
    //     matrix[i][0]==0 ;
    // }
    // }

    }
};