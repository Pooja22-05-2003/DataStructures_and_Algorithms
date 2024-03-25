/*

Problem Link :https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1



TC:O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
The maximum size of the priority queue can be E so after at most E iterations the priority queue will be empty and the loop will end. Inside the loop, there is a pop operation that will take logE time. This will result in the first O(E*logE) time complexity. 
Now, inside that loop, for every node, we need to traverse all its adjacent nodes where the number of nodes can be at most E. If we find any node unvisited, we will perform a push operation and for that, we need a logE time complexity. So this will result in 
the second O(E*logE). 


SC:O(E) + O(V), where E = no. of edges and V = no. of vertices. O(E) occurs due to the size of the priority queue and O(V) due to the visited array. If we wish to get the mst, we need an extra
O(V-1) space to store the edges of the most.
*/
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
      // adj=> node-> adjacent node , weight
      // For MST, we need Min-Heap
      // {weight,node}
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      
      vector<int>InMST(V,0);
      // Here we need not to maintain the parent.
      // If in question it is required to maintain the parent, u can do that.
      
      int sum=0;
      
      // Put any one node in the PQ,lets put the 0th node, and cost of reaching at the 0th node is 0.
      pq.push({0,0});

      while(!pq.empty())
      {
          auto it = pq.top();
          int weight=it.first;
          int node=it.second;
          pq.pop();
          if(InMST[node]==1) continue;
           
           sum+=weight;

           InMST[node]=1;

          
          // traverse all the adacent nodes
          for(auto it : adj[node])
          {
              int newnode=it[0];
              int newweight=it[1];
             
              
                  // it meand the current node is not visited
            if(InMST[newnode]==0)pq.push({newweight,newnode});
                  
              
          }
          
      }
      
      return sum;
    }
};