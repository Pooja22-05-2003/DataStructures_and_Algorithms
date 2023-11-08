/*
Observation:-> If you want to know the number of pairs (x,y) such that x + y = k ; answer is minimum(frequency(x);frequency(y)) -> this formula is only correct if x!=y 

According to Akash’s Law:-> if x==y then ans+=freq(x)/2 
Algorithm:-> We can easily convert our array into hashmap <number,frequency> 

You can run the algorithm for K = 1 ; 
You can run the algorithm for K = 2 ;
.
.
.
.
.
.
.
..
You can run the algorithm for K = sum of two largest numbers(maximum pair sum.)
Out of all these choices pix the maximum answer and your job is done. 

-> https://ideone.com/L9Q3Rd 

-> One smart solution also :-> What can be the values of K -> it can only be the sum of different pairs in the array

-> Harsh Patel’s Law :-> the possible values of k are only the sums of pairs in array 

*/
// TC=O(2N)==O(N)
// SC=O(N)


#include <bits/stdc++.h>
using namespace std;

  int solve(vector<int>& nums,int n, int k) {
        unordered_map<int,int> mp;
        unordered_map<int,bool> vis;

        for(auto it : nums){
            mp[it]++;
            vis[it]=false;
        }

        int ans=0;
        
        for(int i=1;i<=n;i++){
            int el=nums[i];
            int partner=k-el;
            if(vis[partner]==false && vis[el]==false){
                if(el==partner){
                    ans=ans+(mp[el])/2;

                }
                else {
                ans=ans+min(mp[el] ,mp[partner]);

                }
                vis[el]=true;
                vis[partner]=true;
            }
        }

        return ans;

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
        cin>>n;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        int ans=0;
        int j=0;
        while(j<=2000000000){
            int  s=solve(arr,n,j);
            ans=max(s,ans);
            j=j+1;
        }

        cout<<ans<<endl;

        return 0;
}






/*

input :
5
1 2 6 6 5



output :
2

input 2:


output :


*/



