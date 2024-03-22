#include<bits/stdc++.h>
using namespace std;


// TC=O(V+2E)
// SC=O(N)
class Solution {
  public:
   
    bool bfs(int st,int parent,vector<int> adj[],vector<int>&vis)
    {
       vis[st]=true;
       
       queue<pair<int,int>>q;
       q.push({st,parent});
       
       while(!q.empty())
       {
           int frontNode=q.front().first;
           int ParentFrontNode=q.front().second;
           q.pop();
           
           for(auto it : adj[frontNode])
           {
               if((vis[it]==true) && (ParentFrontNode!=it)) 
               {
                //   cout<<"it:"<<it<<" ParentFrontNode: "<<ParentFrontNode<<endl;
                   return true;
               }
               if(!vis[it]) 
               {
                   q.push({it,frontNode});
                   vis[it]=true;
               }
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
                if(bfs(i,-1,adj,vis)) 
                {
                    return true;
                }
            }
         }
         return false;
       
    }
};