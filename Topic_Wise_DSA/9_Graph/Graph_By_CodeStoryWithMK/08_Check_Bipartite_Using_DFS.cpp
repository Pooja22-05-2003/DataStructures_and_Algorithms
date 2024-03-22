// TC=O(V+2E)
// SC= O(2V)=O(V)

// Probelm Link :https://www.geeksforgeeks.org/problems/bipartite-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int currNode, int CurrColor,vector<int>adj[],vector<int>&color)
    {
        color[currNode]=CurrColor;
        
        for(auto it : adj[currNode])
        {
            // If that node is coloured with the same node, so it is not bipartite,
            // As two adjacent nodes are already coloured with the same colour.
            if(color[it]==CurrColor) return false;
            if(color[it]==-1)
            {
                int newColor=1-CurrColor; // if prev color is 0, then currcolor=1 and vice versa
                if(dfs(it,newColor,adj,color)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	               if(dfs(i,1,adj,color)==false) return false;
	        }
	    }
	    
	    return true;
	}

};