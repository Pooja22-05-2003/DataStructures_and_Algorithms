/*✨✨✨✨
Better Approach- Hashing
-> Do the matrix traversal:
-> If any column contain 0 then corresponding to that column matrix mark it to 1
-> If any row contain 0, then correspoding to that row matrix mark it to 1


->Now again do the whole matrix traversal, if u are finding any correspong to any iand j , if any one of the hash array contain 1, mark it to 0

*/


//  Time Complexity=O(2*(n*m))
//  Space Complexity=O(n)+O(m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int> RowHashing(n,0);
        vector<int> ColHasing(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    RowHashing[i]=1;
                    ColHasing[j]=1;
                }
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(RowHashing[i]==1 || ColHasing[j]==1) matrix[i][j]=0;
            }
        }
    }
};