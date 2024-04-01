
// TC=O(2^n)
// SC=O(n)

class Solution
{
    public:
    int solve(int ind, int Capacity,int wt[], int val[])
    {
        // base case
        
        // if(Capacity==0) return 0; // this base case u not need to write, //❌❌
        if(ind==0)  
        {
            if(wt[0]<=Capacity) return val[0]; // ✨✨ ThiThis base case write correctly, when ind==0 then only u will check this base case
            return 0;
        }
       
        
        int notTake=0+solve(ind-1,Capacity, wt,val);
        int take=INT_MIN;
        if(wt[ind]<=Capacity)
        {
            take=val[ind]+solve(ind-1,Capacity-wt[ind],wt,val);
        }
        
      
        return max(notTake,take);
        
        
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return solve(n-1,W,wt,val);
    }
};