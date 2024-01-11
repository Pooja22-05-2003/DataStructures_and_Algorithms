/*
Brute force :
 2 for loop solution

*/





// TC=O(n2)
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> A,vector<int>B , int n , int c , int d){
    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if((A[i]-A[j]+c)==(B[i]-B[j]+d))ans++;
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
