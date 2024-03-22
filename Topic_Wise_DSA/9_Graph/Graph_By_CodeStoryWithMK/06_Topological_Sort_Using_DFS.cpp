// TC=O(V+2E)
// SC=O(3N) [Recursion stack space + Visited + Stack]

#include <bits/stdc++.h>
using namespace std;

void TopologicalSortDFS(int st,vector<int>adj[], vector<int>&vis,stack<int>&s )
{
    vis[st]=true;

    for(auto it : adj[st])
    {
        if(!vis[it]) TopologicalSortDFS(it,adj,vis,s);
    }

    s.push(st);
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

    vector<int>vis(n,0);
    stack<int>s;

    for(int i=0;i<n;i++)
    {
        if(!vis[i]) TopologicalSortDFS(i,adj,vis,s);
    }

    vector<int>ans;

    while(!s.empty())
    {
        int x=s.top(); s.pop();
        ans.push_back(x);

    }
    return ans;
}
