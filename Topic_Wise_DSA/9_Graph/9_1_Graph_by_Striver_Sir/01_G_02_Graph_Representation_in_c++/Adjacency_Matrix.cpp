#include <bits/stdc++.h>
using namespace std;



int main(){

    int n ;
    int m;
    cin>>n;
    cin>>m;

    vector<vector<int>> adj_mat(n+1,vector<int>(m+1));
    // or
    // int adj[n+1][m+1];

    // Take input of all the edges.
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u;
        cin>>v;

        // If Weighted use the weight instead of 1.
        adj_mat[u][v]=1;

        // If weighted use the weight instead of 1.
        adj_mat[v][u]=1;

    }

    return 0;
}
