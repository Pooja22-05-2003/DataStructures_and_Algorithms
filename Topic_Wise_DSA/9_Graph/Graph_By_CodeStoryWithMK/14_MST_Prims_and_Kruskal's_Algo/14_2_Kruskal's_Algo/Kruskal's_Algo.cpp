/*
Problem Link: https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1

Kruskal's Algo:
Time Complexity: O(N+E) + O(E logE) + O(E*4α*2)   where N = no. of nodes and E = no. of edges. 
O(N+E) for extracting edge information from the adjacency list. O(E logE) for sorting the array 
consists of the edge tuples. Finally, we are using the disjoint set operations inside a loop. The 
loop will continue to E times. Inside that loop, there are two disjoint set operations like findUPar() 
and UnionBySize() each taking 4 and so it will result in 4*2. That is why the last term O(E*4*2) is added.

Space Complexity: O(N) + O(N) + O(E) where E = no. of edges and N = no. of nodes. O(E) space is taken 
by the array that we are using to store the edge information. And in the disjoint set data structure, 
we are using two N-sized arrays i.e. a parent and a size array (as we are using unionBySize() function 
otherwise, a rank array of the same size if unionByRank() is used) which result in the first two terms O(N).

*/
class Solution
{
	public:
	
	vector<int>parent;
	vector<int>rank;
	
	int Findparent(int x)
	{
	    if(x==parent[x]) return x;
	    
	    return parent[x]=Findparent(parent[x]);
	}
	
	void Union(int x, int y)
	{
	     int x_parent = Findparent(x);
        int y_parent = Findparent(y);
    
        if (x_parent == y_parent) 
            return;
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Create vector which store 3 things
        // weight,u,v
        parent.resize(V);
        rank.resize(V,0);
        
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
        }
        vector<pair<int,pair<int,int>>>v;
        
        // TC=O(V+E)
        for(int i=0;i<V;i++){
        for(auto it : adj[i])
        {
            int u=i;
            int vv=it[0];
            int weight=it[1];

            v.push_back({weight,{u,vv}});
        }
        }
        
        // sort all the edges according to the weight
         // TC=E(LogE)
        sort(v.begin(),v.end());
        
        // traverse one by one all the edges and if u and v both belong to different components,
        // then pick that edge and add weight in your final mstweight and union the 2 nodes.
        int MstWt=0;
        for(auto it : v)
        {
            int wt=it.first;
            int u=it.second.first;
            int vv=it.second.second;
           
            // DSU:E*(4*alpha)
            if(Findparent(u)!=Findparent(vv))
            {
                
               MstWt+=wt;
               Union(u,vv);
               
               
            }
        }
        
        return MstWt;
    }
};