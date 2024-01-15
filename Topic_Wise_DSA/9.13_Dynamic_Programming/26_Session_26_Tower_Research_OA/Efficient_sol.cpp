// TC=O(N)
// SC=O(N)

#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int  solve(int n , vector<int> arr1 , vector<int> arr2)
{
    map<int,int> mp1;
    map<int,int> mp2;

  
    for(int i=1;i<=n;i++) mp1[arr1[i]]++;
    for(int i=1;i<=n;i++) mp2[arr2[i]]++;
    
  
    //(arr1) dp1[i]-> represent , when i is considered as the maximum element , so all the valid subset till i  , will store in dp[i]
    // (arr2) dp2[i] -> represent , when i is considered as the maximum element , so all the valid subset till i  , will store in dp[i]
    vector<int> dp1(100000,0);
    vector<int> dp2(100000,0);

    int i=1;
    int min_el_cnt=0;
    while(i<=100000){
        int max_el=mp1[i];
        dp1[i]=(pow(2,min_el_cnt))*((pow(2,max_el))-1);
        min_el_cnt=min_el_cnt+mp1[i];
       
        i++;
    }

    i=1;
    min_el_cnt=0;
    while(i<=100000){
        int max_el=mp2[i];
        dp2[i]=(pow(2,min_el_cnt))*((pow(2,max_el))-1);
        min_el_cnt=min_el_cnt+mp2[i];
      
        i++;
    }

    // Main loop 
    // i=1;
    // int ans=0;
    // while(i<=100000){
    //     int j=1;
    //     while(j<=i){
    //         ans+=(dp1[i]*dp2[j]);
    //         j++;
    //     }


    //     i++;
    // }
   

    // Optimized Code

    vector<int> prefx_dp2(100000,0);

    for(int i=1;i<100000;i++){
        prefx_dp2[i]=prefx_dp2[i-1]+dp2[i];
    }
    i=1;
    int ans=0;
    while(i<=100000){
        ans+=dp1[i]*prefx_dp2[i];
        i++;
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

   vector<int> v1(n+1);
   for(int i=1;i<=n;i++){
    cin>>v1[i];
   }
   vector<int> v2(n+1);
   for(int i=1;i<=n;i++){
    cin>>v2[i];
   }

    
    cout<<solve(n,v1,v2)<<endl;

	return 0;
}
	


/*
// input1 :
3
4 5 6 
1 2 3 

// output1:
49


Input2:


// output 2:


input3:


output:


input4:

output: 



*/