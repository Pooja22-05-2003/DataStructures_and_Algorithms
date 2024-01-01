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
