#include<bits/stdc++.h>
using namespace std;

// TC=O(V+2E)
// SC=O(2V)=O(V) [One O(V) for the ans, and one O(V) for the visited]

class Solution {
  public:
    
    
    void dfs(int st,vector<bool>&vis,vector<int> adj[],vector<int>&ans)
    {
        if(vis[st]==true) return ;
        ans.push_back(st);
        vis[st]=true;
        
        for(auto it:adj[st])
        {
            if(!vis[it]) dfs(it,vis,adj,ans);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<bool>vis(V,0); // SC=O(N)
        dfs(0,vis,adj,ans);
        return ans;
        
    }
};