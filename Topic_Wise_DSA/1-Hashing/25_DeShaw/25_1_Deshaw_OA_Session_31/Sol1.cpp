/*
Approach:

Example:-> 

G = p1 + p3 - (p2 + p4)

If you want to make G bigger what should you do ? 

According to Tarab’s law:-> To maximize G, we should maximize p1 and p3 and minimize p2 and p4

-> We have to find two non-intersecting subarrays whose sum is as minimum as possible. The second subarray should always contain the last element 
 If you find them ; then p1 and p3 is already fixed so you don't need to check for it 



P1 should for sure contain the first element of the array or it should be empty 

P4 should contain the last element of the array or it should be empty 
=>[1 2 1 -5]
G = p1 + p3 - (p2+p4) = 4 - (-5) = 9. 


Structure of p4 : [n,n] 
[n-1;n]
[n-2;n]
.
.
.
.
.
.
[1;n] 
Or empty  = 0 

Structure if p2 : [i…j] i<=j ; i→1 t o n ; j→1 to n 

Subarray :-> Always analyze the condition or subarray at index “i” ; and fix something to index “i”

Let's take an index “i”; find the p2 ending at index “i” ; then find p4 ; do these for all “i”; min of all of them will be your answer 

*/





// TC=O(3*N)==O(N)
// SC=O(2*N)==O(N)


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int n ) {
    // calculate suffix[i]=p4 array 
    //  p4[i] (telling minimum subarray starting at index i and ending at index n )must end with a , or it can be empty
    vector<int> p4(n+2);
    
    // p4 can be empty as well
    p4[n+1]=0;
    int sum=0;
    for(int i=n;i>=1;i--){
        sum+=nums[i];
        p4[i]=min(sum,p4[i+1]);
    }

    vector<int> p2(n+1);
    // p2[i]--> tell u that minimum subarray ending at index i and starting from 1
    // if p1 is empty then p3 can also be empty
   
    p2[0]=0;
    for(int i=1;i<=n;i++){
        p2[i]=min(nums[i],(p2[i-1]+nums[i]));
    }


    //  g is the sum of minmum possible subbarray sum in the whole array (p2+P4)
    int g=INT_MAX;
    int t=0;
    for(int i=0;i<=n;i++){
        int summ=min(t,p2[i])+min(p4[i+1],t);
        g=min(g,summ);
    }

    // now we need to maximum difference between (p1+p3)-(p2+p4)
    // so , we got (p2+p4), which is present in g
    // -> So totalSum-g (will giv us p1+p3)
    //  now we want to tell the diff, so we to minum (p1+p3)-(p2+p4)
    // Sp do directly (totalSum-2*g)

    int totalSum=0;
    for(int i=1;i<=n;i++){
        totalSum+=nums[i];
    }
    return (totalSum-(2*g)) ;

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

    cout<<solve(arr,n);
}






/*

input :
6
-3 4 -5 2 6 -5


output :
19

input 2:
3
-4 1 -1

output :
6

*/



