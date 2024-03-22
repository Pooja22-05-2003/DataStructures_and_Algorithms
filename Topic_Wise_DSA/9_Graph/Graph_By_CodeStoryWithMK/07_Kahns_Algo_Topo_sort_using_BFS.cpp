// TC=O(V+2E)
// SC= O(3V)=O(V)

// Remeber , here connected components are not there, so u need to write code for connected components.

// Que Link :https://www.codingninjas.com/studio/problems/topological-sorting_973003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
using namespace std;

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
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int n) {
    // Write your code here!

    vector<int>adj[n];
    for(int i=0;i<edges;i++)
    {
        int u=graph[i][0];
        int v=graph[i][1];
        adj[u].push_back(v);
    }

    vector<int>ans;
    // vector<int>vis(n,0);
    vector<int>Indegree(n,0);
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            Indegree[it]++;
        }
    }
    // for (int i = 0; i < n; i++) {
        // if(!vis[i]) 
        TopologicalSortUsingKahnsAlgo(0,ans,adj,Indegree);
    // }
    return ans;
}
