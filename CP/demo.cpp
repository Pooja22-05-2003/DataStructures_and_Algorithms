
/*
Approach :

*/
// TC=O(N*target)
// SC=O(N*Target)

#include<bits/stdc++.h>
using namespace std;

int solve(int n ,int m, int k, vector<vector<int>> matrix){
    
    vector<vector<bool>>dp(n+1,vector<bool>(5000,false));

    // base case
    dp[0][0]=true;

    for(int i=1;i<=n;i++){

        // iterate through alll the possible sum 
        for(int sum=1;sum<=5000;sum++){
            for(int j=1;j<=m;j++){

                int el=matrix[i][j];
                if(sum-el>=0)
                {
                    if(dp[i-1][sum-el]==true){
                        // it means till i index , we were able to achieve the sum
                        dp[i][sum]=true;
                    }
                }
            }
        }
        
    }

    int ans=INT_MAX;
    int max_possible_sum=5000;
    for(int i=1;i<=5000;i++){
        if(dp[n][i]==true){
            int diff=abs(k-i);
            ans=min(ans,diff);
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
//

    //*********

   int n;
   cin>>n;

    int m;
    cin>>m;

 
    int k;
    cin>>k;

    vector<vector<int>> matrix(n+1, vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>matrix[i][j];
        }
    }
    int ans=solve(n,m,k,matrix);
    cout<<ans<<endl;
    
	return 0;
}
	


/*
// input1 :
3
1
100 
1
2
3



// output1:
94



Input2:


// output 2:


input3:


output:


input4:

output: 



*/