// TC=O(n*w)
// SC=O(w)

class Solution
{
    public:
  
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   vector<vector<int>>dp(n,vector<int>(W+1,0));
       vector<int>prev(W+1,0);
       vector<int>curr(W+1,0);
       
       for(int j=0;j<=W;j++)
       {
           if(wt[0]<=j) prev[j]=val[0];  // Here we need to check wights with j value because that is our current weight
       }
       
       
       
       for(int ind=1;ind<n;ind++)
       {
           for(int Capacity=1;Capacity<=W;Capacity++)
           {
                 int notTake=0+prev[Capacity] ;
                 int take=INT_MIN;
                 if(wt[ind]<=Capacity)
                 {
                       take=val[ind]+prev[Capacity-wt[ind]];
                  }
        
      
                 curr[Capacity]=max(notTake,take);
           }
           
           prev=curr;
       }
       return prev[W];
    }
};