// TC=O(V+2E)
// SC=O(V)
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void TopologicalSortUsingKahnsAlgo(int st, int &cnt,vector<int>adj[],vector<int>&Indegree)
{
  
    queue<int>q;
    for(int i=0;i<Indegree.size();i++)
    {
        if(Indegree[i]==0) q.push(i);
    }


    while(!q.empty())
    {
        int FrontNode=q.front();
        // ans.push_back(FrontNode);
        cnt++;
        q.pop();

        for(auto it : adj[FrontNode])
        {
            Indegree[it]--;
            if( Indegree[it]==0)
            {
                q.push(it);
                
            }
        }
    }
}
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
   
  
    int cnt=0;
    vector<int>Indegree(n,0);
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            Indegree[it]++;
        }
    }
    
        TopologicalSortUsingKahnsAlgo(0,cnt,adj,Indegree);
        
        if(cnt==n) return false;
        return true;
    
    }
};