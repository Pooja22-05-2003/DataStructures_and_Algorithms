// TC=O(n*m)
// SC=O(n*m)

/*
-> We can solve this problem using hashing.
-> Hash the original array [el->index].
-> Now replace all the elements in the matrix and replace them with the indexes, using hashing array.
-> Now  iterate all the rows in the array and for each row, maintain the maximum possible value
-> And while doing this for each row also maintain the minimum value.
-> Now iterate all the col and maintain the mximum possible value for each row and also update the final minimum value as that will be our answer.

*/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }

        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>matrix(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=mp[mat[i][j]];
            }
        }

        int Minn=INT_MAX;
        // iterate over each row
        for(int i=0;i<m;i++){
            int maxx_Row=INT_MIN;
            for(int j=0;j<n;j++){
                maxx_Row=max(matrix[i][j],maxx_Row);
            }
            Minn=min(Minn , maxx_Row);
        }


        //  similary do for the columns
        for(int j=0;j<n;j++){
            int maxx_Col=INT_MIN;
            for(int i=0;i<m;i++){
                maxx_Col=max(matrix[i][j],maxx_Col);
            }
            Minn=min(Minn ,maxx_Col );
        }

        return Minn;
    }
};






































