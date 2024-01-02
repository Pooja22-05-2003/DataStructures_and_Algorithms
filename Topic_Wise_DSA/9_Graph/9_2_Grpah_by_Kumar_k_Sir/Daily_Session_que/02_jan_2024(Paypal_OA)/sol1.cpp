
#include <bits/stdc++.h>
using namespace std;

vector<int> TopoSortAns(int V, vector<int> adj[]){
    
    vector<int> ans;

    vector<int> inDegree(V,0);

    for(int i=0;i<V;i++){
        // if there is an edge from u--->v , then increment the indegree of v
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }

    queue<int> q;
    
    // Push all the nodes with indegree 0, as these are the hihest number of songs beaten
    for(int i=0;i<V;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }


    // Using bfs , decrease the indegree of adjacent nodes one by one
    while(!q.empty()){
        
        int curr=q.front();
        
        q.pop();
        ans.push_back(curr);

        for(auto it: adj[curr]){
            inDegree[it]--;

            if(inDegree[it]==0){
                q.push(it);
            }
        }
    }
    return ans;
}


vector<int> solve(int n, int m, vector<vector<int>>&mat){
    

    // freq vector, which store the  number of songs which beats song[i] 
    // if freq[i][j]=3 , it means that 3 songs beated song[i]
    //  For example in que in 1st example, 
    // song= 0 , Beats songs={1,2,3} , and number of songs beaten=3

    vector<vector<int>> freq(m,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            // considering arr from j+1 to m-1 index and comparing it with jth ind el
            for(int k=j+1;k<m;k++){
                int x=mat[i][j];
                int y=mat[i][k];
               
                freq[x][y]= freq[x][y]+1;

            }
        }
    }


    // Creating adjacency list for doing topological sort.(As Topo sort will use here)
    // Adj list -> It is of m size , because maximum m songs varieties are possible, or we can say maximum m nodes in the graph are possible.
    vector<int> adj[m];
    
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            //  we don't need self edges nodes
            if(i!=j) 
            {  
            if(freq[i][j]>n/2){
                adj[i].push_back(j);
            }

            // Means number of users are of even numbers
            else if (n%2==0){
                // In questions this special condition is given , that is 2 songs have same popularity , then consider song with lower index will beat song with higher index.
                if(freq[i][j]==freq[j][i] && freq[i][j]==n/2){
                    // consider i---> j ( i song is more popular)
                    adj[i].push_back(j);

                    // make it zero , to lower the freq[j][i]
                    // freq[j][i]=0;
                }

                // It may happen , that freq[i][j] and freq[j][i] is not equal but freq[i][j]==n/2 and not >n/2
                else if (freq[i][j]==n/2){
                    adj[i].push_back(j);
                }

                else {
                    // Do nothing 
                    // freq[i][j]<n/2 
                }
            }
            }

        }
    }
    
    

    // Return simply Topo sort
    // Topo sort can be done by using both dfs and bfs, so here in today's session , sir explained using indegree methos, so used Khan's algorithm of Topo sort.
    return TopoSortAns(m,adj);
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

    vector<vector<int>> mat(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>> mat[i][j];
        }
    }

   
    vector<int> ans=solve(n,m,mat);

    for(auto it : ans) {
        cout<< it<<endl;
    }
    cout<<endl;

    return 0;
}


/*
//  input1 :
5
4
0 1 3 2 
0 2 3 1 
1 0 3 2 
2 1 0 3 
0 3 1 2  



// output1:
0
1
3
2


input 2:
3
3
0 1 2
0 2 1
1 2 0

Output 2:
0
1
2




*/