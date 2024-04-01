//✨✨Only base condition changes in this compared to the knapsack problem, no we can pick multiple el, so at index 0, if the target is divisible by the index 0 element then return that much element.

class Solution{
public:
    int solve(int ind, int Capacity,int wt[], int val[],vector<vector<int>>&dp)
    {
        // base case
        
        // if(Capacity==0) return 0; // this base case u not need to write, //❌❌
        if(ind==0)  
        {
            if(wt[0]<=Capacity) return (Capacity/wt[0])*val[0]; // ✨✨ ThiThis base case write correctly, when ind==0 then only u will check this base case
            return 0;
        }
        
        if(dp[ind][Capacity]!=-1) return dp[ind][Capacity];
       
        
        int notTake=0+solve(ind-1,Capacity, wt,val,dp);
        int take=INT_MIN;
        if(wt[ind]<=Capacity)
        {
            take=val[ind]+solve(ind,Capacity-wt[ind],wt,val,dp);
        }
        
      
        return dp[ind][Capacity]=max(notTake,take);
        
        
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
         vector<vector<int>>dp(N,vector<int>(W+1,-1));
         return solve(N-1,W,wt,val,dp);
    }
};