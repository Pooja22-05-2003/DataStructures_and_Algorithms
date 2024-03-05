/*
This is a node-based representation. In this representation, we associate with each node a list of 
nodes adjacent to it. Normally an array is used to store the nodes. The array provides random access to the adjacency list for any particular node.


To create an adjacency list, we will create an array of size n+1 where n is the number of nodes. This array will contain a list, so in C++ list is nothing but the vector of integers.


In this representation, for an undirected graph, each edge data appears twice. For example, nodes 1 and 2 are adjacent hence node 2 appears in the list of node 1, and node 1 appears in the list of node 2. So, the space needed to represent an undirected graph using its adjacency list is 2 x E locations, where E denotes the number of edges.

Space complexity = O(2xE)

This representation is much better than the adjacency matrix, as matrix representation consumes n² locations, and most of them are unused.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n ;
    int m;
    cin>>n;
    cin>>m;

    vector<int> adj[n+1];
    // or
    // int adj[n+1][m+1];

    // Take input of all the edges.
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u;
        cin>>v;

        // If Weighted use the pair<int,int> ( neigbhour edge , weight) instead of normal
        adj[u].push_back(v);

        // If weighted use the weight instead of 1.
        adj[v].push_back(u);
       

    }

    return 0;
}
