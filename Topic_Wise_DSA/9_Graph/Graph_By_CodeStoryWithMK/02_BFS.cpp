#include<bits/stdc++.h>
using namespace std;
// TC=O(V+2E)
// SC=O(3N)=O(N)

class Solution {
  public:
    void bfs(int st, vector<int>adj[],vector<int>&result,vector<int>&vis)
    {
        vis[st]=1;
   
        queue<int>q; // O(N)
        q.push(st);
        
        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();
            result.push_back(frontNode);
            
            // iterate to all the neigbours of the front node
            for(auto it : adj[frontNode])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       vector<int>result; // O(N)
       vector<int>vis(V,0); // O(N)
       bfs(0,adj,result,vis);
       return result;
    }
};