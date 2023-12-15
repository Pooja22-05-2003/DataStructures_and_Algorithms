/*
Optimal soln :
 (ai-aj+c)=(bi-bj+d)
 ai-bi=aj-bj+(d-c)

 Using hash map and precomputing the LHS and adding its count in hash map


*/





// TC=O(n)
// SC=O(n)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> A,vector<int>B , int n , int c , int d){
    unordered_map<int,int> mp;
    int ans=0;
    //  ai-bi=aj-bj+(d-c)
  
    for(int j=1;j<=n;j++){
        int RHS=A[j]-B[j]+(d-c);
        
        ans+=mp[RHS];
        mp[A[j]-B[j]]++;
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
	int n;
    cin>>n;
    int c;
    cin>>c;
    int d;
    cin>>d;
    vector<int>A(n+1,0);
    vector<int>B(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>A[i];
    }

    for(int i=1;i<=n;i++){
        cin>>B[i];
    }

    cout<<solve(A,B,n,c,d)<<endl;
	return 0;
}
	


/*
// input1 :
5
2
2
1 2 3 4 5
1 2 3 4 5


// output1:
10

// input 2 :


// output 2:

*/
