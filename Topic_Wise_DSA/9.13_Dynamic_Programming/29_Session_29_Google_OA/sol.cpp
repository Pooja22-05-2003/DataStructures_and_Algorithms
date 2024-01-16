/*
Problem in 1 Line :
We are given an array, so we need to find the maximum length of the consecutive elements and 
that element order doesn't matter. So, return that maximum length .

We can do some operation , but we are allowed to do any one of the operation in each element.
1st option is : ai=ai+1 (Increment by 1)
2nd option is : ai=ai+0 (Do nothing)


Approach :

1. We need to find the longest consective length , when the last element is i.

// dp[i]=> It indicate the maximum consecutive lenght in the arr.
2. So we have 2 options for that. 
 2.1 If i is present in the array, then dp[i]=dp[i-1]+1
 2.2 Other option is that prev frequency element is greater than 2, so we can increment one prev element by 1.
 if(freq[i-1]>=2) dp[i]=g[i-1]
-----> Here we introduced new g array , so g[i]=> (g[i]= same as ans[i] but you are ignoring 1 occurrence of i) .



*/

// TC=O(N)
// SC=O(N)

#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> arr1){
    // becasue element range given is 10^5
    vector<int> dp(100000,0);
    vector<int> g(100000,0);

    unordered_map<int,int> freq;
    // store the freq of each element of the arr.
    for(int i=1;i<=n;i++){
        freq[arr1[i]]++;
    }

    int maxx_len=0;
    // we will run loop for each element which can be possible .
    int i=1;
    while(i<=100000){

        // handling dp arr case.
        if(freq[i]>=1){
            dp[i]=1+dp[i-1];

        }
        else {
            // use the g array to convert i-1 el to i....by incrementing it by 1.
            if(freq[i-1]>=1){
                dp[i]=1+g[i-1];
            }
            else {
                dp[i]=0;
            }
        }


        // Now we need to also handle the g array case

        //  we are checking greater than equal to 2 becasue, 1 g[i]===ans[i]...ignoring 1 occurrece of i
        if(freq[i]>=2){
            g[i]=1+dp[i-1];
        }

        else if (freq[i]==1){
            //  we can use the prev ele and increment it by 1...so now the current el have feq=1
            if(freq[i-1]>=1){
            g[i]=1+g[i-1];
            }
            else g[i]=0;

        }
        else {
            g[i]=0;
        }

        maxx_len=max(maxx_len,dp[i]);
        i++;
    }
   
    return maxx_len;
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
    int ans=solve(n,v1);
    cout<<ans<<endl;

	return 0;
}
	


/*
// input1 :
9
1 1 3 4 6 6 6 8 10

// output1:
5


Input2:


// output 2:


input3:


output:


input4:

output: 



*/