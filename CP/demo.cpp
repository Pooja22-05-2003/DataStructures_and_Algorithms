/*

*/

// TC=O(N+M)
// SC=O(N+M)


#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int n, int start,int &cnt,vector<bool> &visited) {
    // Initialize visited array
   

    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    q.push(start);

    // Iterate while the queue is not empty
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int u = q.front();
        q.pop();
      //   cout << u << " ";

        // Get all adjacent vertices of the dequeued vertex u.
        // If an adjacent vertex has not been visited, then mark it
        // visited and enqueue it.
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                cnt++;
                q.push(v);
            }
        }
    }
}
int solve(int n , vector<int> &A , vector<int> &B){
//   cout<<"A:"<<A.size()<<"B:"<<B.size()<<endl;
   if(A.size()==0 && B.size()==0) return n;
   // create adjacenecy list.
   int m=A.size();

    vector<int> adj[n+1];
    // or
    // int adj[n+1][m+1];

    // Take input of all the edges.
    for(int i=0;i<m;i++){
        int u,v;
         u=A[i];
         v=B[i];

         //v-->u
        // If Weighted use the pair<int,int> ( neigbhour edge , weight) instead of normal
        adj[v].push_back(u);

        // If weighted use the weight instead of 1.
    }

    vector<bool> visited(n + 1, false);
    int cnt=1;
    bfs(adj,n,B[0],cnt,visited);
    for(int i=1;i<=n;i++)
    {
      if(visited[i]==false) bfs(adj,n,i,cnt,visited);
    }
    return cnt;

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********

    //*********
    // 1-- based indexing are used here

    int n;
    cin >> n ;

    int a;
    cin>>a;

    int b;
    cin>>b;

    vector<int>arr1(a,0);
    for(int i=0;i<a;i++)
    {
      cin>>arr1[i];
    }

    vector<int>arr2(b,0);
    for(int i=0;i<a;i++)
    {
      cin>>arr2[i];
    }

    cout<<"ans:"<<solve(n,arr1,arr2);

}






/*
input1 :

7
6
6
1
2
3
4
6
5
7
6
4
1
2
1

Output 1:



input2 :


Output2:







*/
