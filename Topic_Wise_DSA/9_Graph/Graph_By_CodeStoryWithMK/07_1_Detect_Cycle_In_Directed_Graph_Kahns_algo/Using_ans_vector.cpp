// TC=O(V+2E)
// SC=O(V)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void TopologicalSortUsingKahnsAlgo(int st, vector<int>&ans,vector<int>adj[],vector<int>&Indegree)
{
    // vis[st]=1;
    queue<int>q;
    for(int i=0;i<Indegree.size();i++)
    {
        if(Indegree[i]==0) q.push(i);
    }


    while(!q.empty())
    {
        int FrontNode=q.front();
        ans.push_back(FrontNode);
        q.pop();

        for(auto it : adj[FrontNode])
        {
            Indegree[it]--;
            if( Indegree[it]==0)
            {
                q.push(it);
                // vis[it]=1;
            }
        }
    }
}
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
   
         vector<int>ans;
  
    vector<int>Indegree(n,0);
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            Indegree[it]++;
        }
    }
    
        TopologicalSortUsingKahnsAlgo(0,ans,adj,Indegree);
        
        if(ans.size()==n) return false;
        return true;
    
    }
};