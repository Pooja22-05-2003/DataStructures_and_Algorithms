/*
1.First create graph. (Adjacency list).
2. Then first put all the nodes , which have 0 and 1 adjacenet nodes connected to it. because at time=1, this will start dsiappearing.
3. Go in while loop and repeat this , until u find even one edges, else break the loop.
4. Inside the loop, for all the edges which are disappearing, mark them visiited and 
all the adjacent nodes , which are connected to this disppearing edge, deceaese their indegree. and if after decreasing , its degree become 0,1, put them in the queue.
5. After one iteration , increase the counter of time.
6. After all the iterations, return the totoal time.

*/


// TC=O(N+M)
// SC=O(N+M)


#include <bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> &A , vector<int> &B){
   
   // create adjacenecy list.
   int m=A.size()-1;

   vector<int>adj[n];
   vector<int>InDegree(n,0);
   for(int i=1;i<=m;i++)
   {
      adj[A[i]].push_back(B[i]);
      adj[B[i]].push_back(A[i]);
      InDegree[A[i]]++;
      InDegree[B[i]]++;

      
   }

   queue<int> q;

   vector<int>vis(n,0);
   // push all the nodes , which have indegree =1;

   for(int i=0;i<n;i++)
   {
      if(InDegree[i]==0 || InDegree[i]==1) 
      {
         q.push(i);
          vis[i]=1;
         // cout<<"i:"<<i<<" it:"<<InDegree[i]<<endl;
        
      }
   }

   int flag=1;
   int time=0;
   if(q.size()==0) flag=0;
   else // do nothing
  
   while(flag==1)
   {
        queue<int> newQueue;
      while(!q.empty()){//}
      int disappear=q.front();q.pop();
     

      for(auto it : adj[disappear])
      {
         InDegree[it]--;
         if(vis[it]==0 && (InDegree[it]==0 || InDegree[it]==1))
         {
            newQueue.push(it);
             vis[it]=1;
         }
      }
      }
       time++;
      q=newQueue;
      if(q.size()==0) flag=0;
      
   }

   return time;

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

    int m;
    cin>>m;
    vector<int> arr(m+1,0);
    for(int i=1;i<=m;i++){
      cin>>arr[i];
    }

    vector<int>arr2(m+1,0);
    for(int i=1;i<=n;i++)
    {
      cin>>arr2[i];
    }
    

    cout<<"ans:"<<solve(n,arr,arr2);

}






/*
input1 :
7
5
0 1 2 4 5
1 2 3 5 6

Output 1:
ans:2


input2 :
4
4
0 1 2 3
1 2 3 0

Output2:
ans:0






*/
