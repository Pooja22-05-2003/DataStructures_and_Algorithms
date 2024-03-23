#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity : O( E log(V) ) 

Where E = Number of edges and V = Number of Nodes.

Space Complexity : O( |E| + |V| ) 

Where E = Number of edges and V = Number of Nodes.
*/
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector <int> ans;     
        vector<int>Dis(V,INT_MAX);   // O(N) [SC]
        Dis[S]=0;
        
        // We Take Priority Queue[Min-Heap], It will store the minimum distance node at the top.
        set<pair<int,int>>s; // O(n) [SC]
        
        // Pushing the source node in the pq, with dist=0;
        // Pq-{dist,node}
        s.insert({0,S});
        
        while(!s.empty())
        {
            auto curr=*(s.begin());
            s.erase(curr);
            int dist=curr.first;
            int node=curr.second;
            
            // traverse all its adjcent nodes.
            for(auto it : adj[node])
            {
                int AdjNode=it[0];
                int newDist=it[1];
                int sum=(dist+newDist);
                
                if( sum< Dis[AdjNode])
                {
                    if(Dis[AdjNode]!=INT_MAX)
                    {
                        // Delete that node entry from Set
                        
                        s.erase({AdjNode,newDist});
                        //or
                        /*
                        auto iter=s.find({AdjNode,newDist});
                        s.erase(iter);
                        */
                    }
                    Dis[AdjNode]=sum;
                    s.insert({sum,AdjNode});
                }
            }
        }
        
        return Dis;
    }
};