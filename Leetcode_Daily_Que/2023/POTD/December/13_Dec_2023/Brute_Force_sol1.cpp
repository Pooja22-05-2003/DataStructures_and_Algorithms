// TC=O(n*m*(n+m))
// SC=O(1)
class Solution {
public:
    bool valid (vector<vector<int>>& mat ,int  p, int  q){
        int row=mat.size();
        int col=mat[0].size();

        for(int j=0;j<col;j++){
            if(mat[p][j]!=0 && j!=q) return false;
        }

        for(int i=0;i<row;i++){
            if(mat[i][q]!=0 && i!=p) return false;
        }

        return true;


    }
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( mat[i][j]==1 && valid(mat,i,j)) cnt++;
            }
        }

        return cnt;
    }
};