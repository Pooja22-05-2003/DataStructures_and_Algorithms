#include<bits/stdc++.h>
using namespace std;


// Time Complexity =O(E*log(V))

	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<pair<int,int>> adj[], int S)
    {
        // We need to find the shortest distance from source node to each node.
        vector<int> ans;
        
        // PQ= {distance----> node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,S});
        vector<int>Distance(V,INT_MAX);
        Distance[S]=0;
        while(!pq.empty()){
            auto it=pq.top();
            int dist=it.first;
            int node=it.second;
            pq.pop();
            
            for(auto it : adj[node]){
                int newdist=dist+it.second;
                int newNode=it.first;
               
                
                
                if(newdist<Distance[newNode]){
                    Distance[newNode]=newdist;
                   
                    pq.push({newdist,newNode});
                }
                
            }
            
        }
        
        return Distance;
    }


//{ Driver Code Starts.


int main()
{
        #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********
    int n ;
    int m;
    cin>>n;
    cin>>m;

    vector<pair<int,int>> adj[n];
    // or
    // int adj[n+1][m+1];

    // Take input of all the edges.
    for(int i=0;i<m;i++){
        vector<int>t;
        int u,v,w;
        cin>> u ;
        cin>>v;
        cin>>w;
        

        // If Weighted use the pair<int,int> ( neigbhour edge , weight) instead of normal
        adj[u].push_back({v,w});

        // If weighted use the weight instead of 1.
        adj[v].push_back({u,w});
       

    }

    int S;
    cin>>S;
    	vector<int> res = dijkstra(n, adj, S);
    	
    	for(int i=0; i<n; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    

    return 0;

}

// } Driver Code Ends

/*
// input1 :

// see the pictorial diagram of graph o gfg website input 1.
6 5
0 3 9
0 5 4
1 4 4
2 5 10
4 5 3
1


// output1:
11 0 17 20 4 7 

Input2:

// output 2:



input3:


output:


input4:

output: 



*/