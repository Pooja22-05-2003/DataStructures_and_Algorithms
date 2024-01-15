/*
Approach :
Problem in 1 line : Find the number of pairs , 1 pair is considered valid, 
 when u pick 2 subsets , 1 subset from arr1 and another subset from arr2, such that
 max_el of subset 1 >= max_el of subset2.

 As we need to return the count and it can go so large , so return the answer in mod 1e9+7


1. Let's say x is the maximum element of s1 . so with this maximum element , we  can create so many subsets and in the valid
subset we can pick all those element which are less than equal to this max_el in the valid subset.

So , if n is given , then the number of subset would be = 2^n.

NOTE: Lets' say max  element count is more than 1 in the array , so its forumula would be (2^y-1) [ y is the count of the occurence in the arr] and we are
subtracting -1 because we are removin the empty subset. , because in RHS atleast we need the max_elememnt in the subset, so we can't comsider empty subsets int that.

NOTe= If we are pickign 1 subset (RHS) [max_el] from arr1, then we need to pick all the less element subset pair from the arr2.

*/
// TC=O(N2)
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
    
    cout<<"mp2.size():"<<mp2.size()<<endl;
    //(arr1) dp1[i]-> represent , when i is considered as the maximum element , so all the valid subset till i  , will store in dp[i]
    // (arr2) dp2[i] -> represent , when i is considered as the maximum element , so all the valid subset till i  , will store in dp[i]
    vector<int> dp1(100,0);
    vector<int> dp2(100,0);

    int i=1;
    int min_el_cnt=0;
    while(i<=100){
        int max_el=mp1[i];
        dp1[i]=(pow(2,min_el_cnt))*((pow(2,max_el))-1);
        min_el_cnt=min_el_cnt+mp1[i];
        cout<<"dp1[i]:"<<dp1[i]<<endl;
        i++;
    }

    i=1;
    min_el_cnt=0;
    while(i<=100){
        int max_el=mp2[i];
        dp2[i]=(pow(2,min_el_cnt))*((pow(2,max_el))-1);
        min_el_cnt=min_el_cnt+mp2[i];
        cout<<"dp2[i]:"<<dp2[i]<<endl;
        i++;
    }

    // Main loop 
    i=1;
    int ans=0;
    while(i<=100){
        int j=1;
        while(j<=i){
            ans+=(dp1[i]*dp2[j]);
            j++;
        }


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

    for(int i=1;i<=n;i++){
        cout<<v1[i]<<" "<<v2[i];
    
    }
    cout<<solve(n,v1,v2);

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