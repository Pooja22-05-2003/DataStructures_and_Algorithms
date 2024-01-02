/*
1. One image matrix is given and source (row,col) is also given, change the value of the row,col to the color value given in the que in the ans matrix, and mark that row,col as vis.
2. Now travel to all the 4 dimension adjacent cells, and is they are not visited and they equal to the previos el value, then change their color in the ans matrix and mark them as visited.
3. Repeat this , till queue does not get empty.
4. Return the final ans matrix as the answer.
*/

// TC=O(3*(m*n))== O(m*n)
// SC=O(m*n*4)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r=image.size();
        int c=image[0].size();
         vector<vector<int>> vis(r,(vector<int>(c,0)));
         vector<vector<int>> ans=image;
         
         queue<pair<int,int>>q;
         ans[sr][sc]=color;
         q.push({sr,sc});
         vis[sr][sc]=1;

        int adjRow[4]={0,-1,0,1};
        int adjCol[4]={-1,0,1,0};
        while(!q.empty()){
             auto curr=q.front();
            
             int row=curr.first;
             int col=curr.second;

              
             q.pop();

             for(int i=0;i<4;i++){
                 int newRow=row+adjRow[i];
                 int newCol=col+adjCol[i];

                
            
                 if(newRow<r && newRow>=0 && newCol<c && newCol>=0){
                     
                    if( image[newRow][newCol]==image[row][col] && !vis[newRow][newCol])
                    { vis[newRow][newCol]=1;
                     ans[newRow][newCol]=color;
                     q.push({newRow,newCol});
}
                 }
             }
             
         }
        return ans;
    }
};