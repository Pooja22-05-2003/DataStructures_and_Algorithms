// TC=O(V+2E)
// SC= O(2V)=O(V)

// Probelm Link :https://www.geeksforgeeks.org/problems/bipartite-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int currNode, int CurrColor,vector<int>adj[],vector<int>&color)
    {
        color[currNode]=CurrColor;
        
        queue<pair<int,int>>q;
        q.push({currNode,CurrColor});
        
        while(!q.empty())
        {
            auto it =q.front(); q.pop();
            int FrontNode=it.first;
            int NodeColor=it.second;
            
            for(auto it : adj[FrontNode])
            {
                if(color[it]==NodeColor) return false;
                if(color[it]==-1)
                {
                    int newColor=1-NodeColor;
                    if(color[it]==-1)
                    {
                    q.push({it,newColor});
                    color[it]=newColor;
                    }
                    
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
	               if(bfs(i,1,adj,color)==false) return false;
	        }
	    }
	    
	    return true;
	}

};