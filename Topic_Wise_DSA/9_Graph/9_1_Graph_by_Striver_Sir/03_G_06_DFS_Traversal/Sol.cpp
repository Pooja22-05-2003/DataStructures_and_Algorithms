// // TC=O(N+2*E)
// // SC= O(3N)==> O(N) [ans,recursion stack space(Max depth of the graph),vis]
#include <bits/stdc++.h>
using namespace std;

// This dfs recursion would be called maximum n times
 void dfs(int st, vector<int> &vis , vector<int> & ans , vector<int> adj[]){
        vis[st]=1;
        ans.push_back(st);
        
        // This adjacecny will go maximum to all degree(2*E)
        for(auto it : adj[st]){
            if(!vis[it]){

                
                dfs(it,vis,ans,adj);
            }
        }
        
    }
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int>vis(V,0);
    
        
        dfs(0,vis,ans,adj);
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

    vector<int> ans=dfsOfGraph(n,adj);

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



// // output1:

0
1
2
4
3





*/