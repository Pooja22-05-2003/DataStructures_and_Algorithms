#include <bits/stdc++.h>
using namespace std;

/*

TC=O(ElogV) [It has the complete derivation for this]
SC= O(2N)=> O(N)
Disadvantage of Dijkstra's Algo:
1. Any graph with negative weights cannot implement dijkstra's algo.
2. It will fall in an infinite loop [EX 0--->1 (weight is -2)], evertime, u get minimum weight
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
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // O(n) [SC]
        
        // Pushing the source node in the pq, with dist=0;
        // Pq-{dist,node}
        pq.push({0,S});
        
        while(!pq.empty())
        {
            auto curr=pq.top();pq.pop();
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
                    Dis[AdjNode]=sum;
                    pq.push({sum,AdjNode});
                }
            }
        }
        
        return Dis;
    }
};