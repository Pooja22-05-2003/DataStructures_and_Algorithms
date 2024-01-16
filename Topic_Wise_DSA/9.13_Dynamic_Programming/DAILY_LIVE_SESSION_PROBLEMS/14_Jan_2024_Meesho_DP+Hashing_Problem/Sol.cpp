/*
Problem in 1 Line. Given an array A. You can peform any number of operation u want.
In 1 operation u can pick the subarray with 1st and last as same element and remove that from the array.
.So after the all operations u need to return the minimum length of the array.

Ex:
input 1:
4
1 2 3 2

output1:
1 [ As we can remove the subarray (2,3,2)] , so remaining subarray is 1. and its legnth is 1.



Input2:
6
4 1 2 2 3 3

output :
2

As first we can remove the subarray(2,2) then the array left is [4 1 3 3]

After that we can remove(3,3). So the array left is [4 1] and its length is 2. So, answer is 2.



Approach :

1. One way you can think is that u will the the maximum length subarray with first and last element equal.but ther are more options after 
removing one subarray , u can even reomve the next subarray . So you can't do in this manner.
2. Actually in this question u need to think all the possible cases. And u will pick the best answer among all the possible answer.

3. Think about DP🧠🤔🤔:- In Do we explore all the possible paths and at last we pick the best from all those.
4. In dp, dp[i]= Represent the best answer till index i.
5. At each index 'i', u have 2 options , first is that u pick the current index element and the second option is thaat, u will not pick the current index
element at 'i' in your dp[i].
6. So here there is a need to introduce 1 more dp state. 
7. dp[i][0] represent the best answer to the question ,if u ignored the 'ith' element .
8. dp[i][1] represent the best answer to the question , if u picked the current 'ith' element .
9. So follow the dp pattern and try to formualte the best answer for index 'i'.


10. There is 1 dp array and there is 1 answer array.
In the answer array , we will store the best answer in ans[i].
11. dp[i][1]=1+ans[i-1] // u are taking the ith element
12. dp[i][1]= min ( move the j index from i-1 to 1 and check whether there any element similar to arr[i], if yes then option is ans[j-1] and take min all those possbile ans)
   
    ans[i]= min(dp[i][1] , dp[i][0])
*/




// TC=O(N2)---> We can optimize this using hashing and we can remove the jth loop 
// SC=O(N)

#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int> arr){
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    vector<int> ans(n+1,0);

    dp[1][0]= INT_MAX; // it measn we are trying to find the el  which is similar to curr el and our search space is i-1 to 1.
    dp[1][1]=1;    // we are including the current element at index 'i'.

    ans[1]=min(dp[1][1], dp[1][0]);
    int i=2;
   
    while(i<=n)
    {   
        dp[i][1]=1+ans[i-1];
        dp[i][0]=INT_MAX;
        int j=i-1;
        while(j>=1){
            if(arr[j]==arr[i]){
                dp[i][0]=min(dp[i][0],ans[j-1]);
            }
            j--;
        }
        ans[i]=min(dp[i][1],dp[i][0]);
        
        i++;
    }

    int res=min(dp[n][0] , dp[n][1]);
    return res;
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
6
4 2 2 3 3 1

// output1:
2


Input2:
4
1 2 3 2

// output 2:
1

input3:


output:


input4:

output: 



*/