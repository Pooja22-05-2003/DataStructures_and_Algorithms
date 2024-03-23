#include <bits/stdc++.h>
using namespace std;


int find(vector<int>parent, int node)
{
    
    if(parent[node]==node) return ;

    return parent[node]=find(parent,parent[node]); // This is path compression
}



void unionSetUsing_Rank_And_pathCompression(vector<int>parent,vector<int>rank,int x, int y)
{
    int x_parent=find(parent,x);
    int y_parent=find(parent,y);

    if(x_parent==y_parent) return ; // Already belong to same set

    if(rank[x_parent]> rank[y_parent])
    {
        // Jiska rank big hai, wahi parent banega new set ka. 
        // And Rank kisi ka increase nahi hoga
        parent[y_parent]=x_parent;
    }

    else if(rank[x_parent]<rank[y_parent])
    {
       parent[x_parent]=y_parent;
    }
    else 
    {
        // Means dono parent ka rank same hai.
        // Kisi bhi random ek node ko dusre ka parent bana do.
        // And jo main parent bana hai , uska rank increase kar do.
        parent[x_parent]=y_parent;
        rank[y_parent]++;
    }
}



int main()
{
    vector<int>parent;
    vector<int>rank; // all nodes rank are intialyy 0
}
