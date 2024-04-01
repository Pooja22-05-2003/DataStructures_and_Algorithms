
// Recursion
// TC=O(2^n)
// SC=O(n)
class Solution{
  public:
    int solve(int ind, int c, int price[])
    {
        // base case
        if(ind==0)
        {
            if(c%(ind+1)==0)
            {
                return price[ind]*(c/(ind+1));
            }
            return 0;
        }
        
        int nottake=solve(ind-1,c,price);
        int take=INT_MIN;
        if(c>=(ind+1))
        {
            take=price[ind]+solve(ind,(c-(ind+1)),price);
        }
        return max(nottake,take);
    }
    int cutRod(int price[], int n) {
        //code here
        return solve(n-1,n,price);
    }
};