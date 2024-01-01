// // TC=O(N+2*E)
// // SC= O(3N)==> O(N) [ans,queue,vis]
#include <bits/stdc++.h>
using namespace std;

 vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<int> ans;
    vector<int> vis(V,0);
    queue<int> q;
    q.push(0);
    ans.push_back(0);
    vis[0]=1;

    // This will take O(N) time 
    while(!q.empty()){
        int curr=q.front();
        q.pop();

        // This will total run for total degree=(2*E)
        for(auto it : adj[curr]){
            if(!vis[it]){
                q.push(it);
                ans.push_back(it);
                vis[it]=1;
            }
        }
    }
    return ans;     
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********


    //*********
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

        // If Weighted use the pair<int,int> ( neigbhour edge , weight) instead of normal weight.
        adj[u].push_back(v);

        adj[v].push_back(u);
       

    }

    vector<int> ans=bfsOfGraph(n,adj);

    for(auto it : ans) {
        cout<< it<<endl;
    }
    cout<<endl;

    return 0;
}



/*
// // input1 :
5
4
0 1
0 2
0 3
2 4



// output1:

0
1
2
3
4





*/