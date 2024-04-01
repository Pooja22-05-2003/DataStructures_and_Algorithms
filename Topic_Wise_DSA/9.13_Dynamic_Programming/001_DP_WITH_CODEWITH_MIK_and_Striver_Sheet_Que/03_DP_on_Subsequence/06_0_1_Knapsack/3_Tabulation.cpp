
// TC=O(n*w)
// SC=O(n*w)+ [No Recursion Stack space]

class Solution
{
    public:
  
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,0));
       
       for(int j=0;j<=W;j++)
       {
           if(wt[0]<=j) dp[0][j]=val[0];  // Here we need to check wights with j value because that is our current weight
       }
       
       
       
       for(int ind=1;ind<n;ind++)
       {
           for(int Capacity=1;Capacity<=W;Capacity++)
           {
                 int notTake=0+dp[ind-1][Capacity] ;
                 int take=INT_MIN;
                 if(wt[ind]<=Capacity)
                 {
                       take=val[ind]+dp[ind-1][Capacity-wt[ind]];
                  }
        
      
                 dp[ind][Capacity]=max(notTake,take);
           }
       }
       return dp[n-1][W];
    }
};