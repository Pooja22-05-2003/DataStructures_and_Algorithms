/*
->In the Directed Graph case, we need not to maintatin the Parent. Because in this we can only move in 1 direction only.
-> In case of DFE directed cycle detection, check whther the node is already visited, and it is viisited in the current recursion call, so this contain cycle.


*/

#include<bits/stdc++.h>
using namespace std;


// TC=O(V+2E)
// SC=O(N)


bool dfs(int st , vector<int>&vis , vector<int>adj[],vector<int>&currentRecursion)
{
	vis[st]=true;
	currentRecursion[st]=1;
	for(auto it : adj[st])
	{
		// condition of cycle
		if((vis[it]==1 )&& (currentRecursion[it]==1))
		{
			return true;
		}
		if(!vis[it])
		{
			if(dfs(it,vis,adj,currentRecursion)) return true;
		}
	}

	currentRecursion[st]=0;
	return false;
}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
	vector<int>adj[v];

	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
	}

	vector<int>vis(v,0);
	vector<int>currentRecursion(v,0);
	for(int i=0;i<v;i++)
	{
		if(!vis[i])
		{
		
			if(dfs(i,vis,adj,currentRecursion)) return true;
		}
	}

	return false;
}
