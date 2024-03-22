#include<bits/stdc++.h>
using namespace std;

// TC=O(V+2E)
// SC=O(N)
class Solution {
  public:
   
    bool dfs(int st,int parent,vector<int> adj[],vector<int>&vis)
    {
       vis[st]=true;
       
       for(auto it : adj[st])
       {
        //   if(parent==it) continue;
           if(vis[it]==true && parent!=it) return true;
           if(!vis[it])
           {
               if(dfs(it,st,adj,vis)) return true;
           }
       }
       
       return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])  
            {
                if(dfs(i,-1,adj,vis)) 
                {
                    return true;
                }
            }
         }
         return false;
       
    }
};