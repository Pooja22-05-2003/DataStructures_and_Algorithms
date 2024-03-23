#include <bits/stdc++.h>
using namespace std;

int find(vector<int>parent, int node)
{
    
    if(parent[node]==node) return ;

    return find(parent,parent[node]); // Without path compression
}


void unionSet(vector<int>parent,int x, int y)
{
    int a=find(parent,x);
    int b=find(parent,y);

    if(a==b) return ; // If parents are already same , then they already belong to same set
    parent[x]=y;      // Kisi bhi ek node ko dusre ka parent bana denge.

}
