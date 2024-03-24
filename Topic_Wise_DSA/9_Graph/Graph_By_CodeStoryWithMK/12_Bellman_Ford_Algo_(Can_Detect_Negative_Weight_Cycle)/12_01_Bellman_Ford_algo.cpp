// TC=O(V*E)
// SC=O(N) [For distance vertex]
class Solution {
  public:
  
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    
        vector<int> dis(V,1e8);
        dis[S]=0;
        for(int i=0;i<=(V-1);i++) // TC=O(V*E)
        {
            for(auto it : edges)
            {
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                
                // u-->v
                if(dis[u]!=1e8 && (dis[u]+wt)<dis[v])
                {
                    // then update the weight OR we can say perform the relaxation
                    dis[v]=(dis[u]+wt);
                }
            }
        }
        
        // For detecting cycle, let's do iteration one more time , if weight updated , it means there is a negative cycle.
        for(auto it : edges)
            {
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                
                // u-->v
                if(dis[u]!=1e8 && (dis[u]+wt)<dis[v])
                {
                    // then update the weight OR we can say perform the relaxation
                   return{-1};
                }
            }
            return dis;
        
    }
};