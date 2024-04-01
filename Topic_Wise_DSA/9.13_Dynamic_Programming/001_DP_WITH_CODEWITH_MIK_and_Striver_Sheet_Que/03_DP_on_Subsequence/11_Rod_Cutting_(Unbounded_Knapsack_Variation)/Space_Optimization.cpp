
// Space Optimization
// TC=O(n*n)
// SC=O(n)
class Solution{
  public:
   
    int cutRod(int price[], int n) {
        //code here
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        
        for(int j=0;j<=n;j++)
        {
            int ind=0;
            if(j%(ind+1)==0)
            {
                prev[j]= price[ind]*(j/(ind+1));
            }
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int c=1;c<=n;c++)   // ✨✨here must intialize the value starting from 1 and not 0 and end at n
            {
                int nottake=prev[c];
                int take=INT_MIN;
                if(c>=(ind+1))
                {
                   take=price[ind]+curr[c-(ind+1)];
                }
               curr[c]=max(nottake,take);
            }
            prev=curr;
        }
        return prev[n];
    }
};