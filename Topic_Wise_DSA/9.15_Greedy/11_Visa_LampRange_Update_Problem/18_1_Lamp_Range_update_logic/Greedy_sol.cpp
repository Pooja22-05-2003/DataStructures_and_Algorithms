/*
TC=O(nlogn)
SC=O(n)

// Use this approach, when constraints is so high, If constrainst is of range between 1<=x<=(10^9) [ Then use the Hashing Approach]
*/

#include<bits/stdc++.h>
using namespace std;

void  solve(vector<vector<int>> query, int n ,vector<int>points){

    int b_size=(2*query.size()+(points.size()));
    vector<pair<int,int>>b(b_size);
    int si=query.size();
    int ind=0;
    for(int i=0;i<si;i++)
    {
        int l=query[i][0];
        int r=query[i][1];
        b[ind].first=l;
        b[ind].second=0; // 0 means start point
        ind++;
        b[ind].first=r;
        b[ind].second=2;
        ind++;
    }


    for(int i=0;i<points.size();i++)
    {
        b[ind].first=points[i];
        b[ind].second=1;
        ind++;
    }

    
    sort(b.begin(),b.end());

    map<int,int> count;

    int c=0;
 
    for(int i=0;i<b.size();i++)
    {
        int curr=b[i].first;
        int indentifier=b[i].second;

        if(indentifier==0)
        {
            // it means start point
            c++;
        }
        else if (indentifier==2)
        {
            c--;
        }
        else{
            // it means it is the point
          
            count[curr]=c;
        }
    }


    for(int i=0;i<points.size();i++)
    {
        cout<<count[points[i]]<<",";
    }
}  


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********

    int q ;
    cin>>q;

   
    vector<vector<int>> query(q,vector<int>(2,0));
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        query[i][0]=l;
        query[i][1]=r;


    }
    
    int n;
    cin>>n;
    vector<int>points(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>points[i];
    }
    solve(query,q,points);
    // cout<<ans<<endl;

	return 0;
}
	

/*
input1 :
3
1 7
5 11
7 9
6
7
1
5
10
9
15


Output 1:
3,1,2,1,2,0,




input2 :


Output2:



*/


