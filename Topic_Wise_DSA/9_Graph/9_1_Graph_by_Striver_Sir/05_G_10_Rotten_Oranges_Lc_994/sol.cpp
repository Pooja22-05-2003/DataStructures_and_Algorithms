/*
1. If there is a rotten then it can rott all its neigbour orange in 1 unit of time simultaneously, if they are fresh orange.
2. So in the grid , it is not necessary that there will be only 1 rotten orange. There can be multiple rotten orange.
3. So make one queue and push all the rotten oranges in the queue at once (Push i,j and time ).
4. So perform all the operation on queue until its, empty, and push the adjacent elements at t+1 time.
5. Now after checking for all the queue elements , u run one for loop and check , whether all the fresh oranges are turned to rotten, if yes , then return the time.
5. If even one fresh orange , not able to convert in rotten , then return -1.
*/

// TC=
// SC=O(n*m)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // SC=O(n*m)
        vector<vector<int>> mat=grid;
        
        // SC=O(n*m) // If all the oranges are rotten , than queue can store max (n*m) elements.
        queue<pair<pair<int,int>,int>> q;

        int t=0;

        int r=grid.size();
        int c=grid[0].size();


        // SC=O(n*m)==> Vis array for keeping track.
        vector<vector<int>> vis(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==2) {
                q.push({{i,j},t});
                vis[i][j]=1;
                }
            }
        }

        int adjRow[4]={0,-1,0,1};
        int adjCol[4]={-1,0,1,0};

        // TC=O(n*m*4) [ It may happen that all the oranges in the matrix are fresh and for each time we are  checking all 4 adjacent]
        while(!q.empty()){
            auto cur=q.front();
            int row=cur.first.first;
            int col=cur.first.second;
            int time=cur.second;
            q.pop();
            // calculate the max time
            t=max(t,time);
            for(int i=0;i<4;i++){
                int newRow=row+adjRow[i];
                int newCol=col+adjCol[i];

                if(newRow<r && newRow>=0 && newCol<c && newCol>=0 && mat[newRow][newCol]==1 && !vis[newRow][newCol]){
                    
                    vis[newRow][newCol]=1;
                    q.push({{newRow,newCol},time+1});
                   
                }
            }

        }

                for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){

                    // here u missed the condition to write vis[i][j]==0 (which is the necessary condition indicatiing that the orange is fresh but not visited)
           
                    if(mat[i][j]==1 && vis[i][j]==0) return -1;
                }
                cout<<endl;
            }
        return t;
    }
};