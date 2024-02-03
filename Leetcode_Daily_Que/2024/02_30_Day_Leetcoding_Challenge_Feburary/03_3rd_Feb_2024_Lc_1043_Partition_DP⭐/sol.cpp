// TC=O(n*k)
// SC=O(n)

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);

        dp[1]=arr[1-1];
        int i=2;
        while(i<=n)
        {
            int j=i;
            int maxEl=arr[j-1];
            int len=1;
            int maxSum=arr[j-1];
            if(i<=k)
            {
                int maxElement=arr[1];
                
                while(j>=1)
                {
                    maxElement=max(maxElement,arr[j-1]);
                    j--;
                }
                dp[i]=(i*maxElement);
            }
            else {
            while((j>(i-k)) )
            {
                dp[i]=max(dp[i],(maxSum+dp[j-1]));
               
                 j--;
                
                    maxEl=max(maxEl,arr[j-1]);
                    len++;
                    maxSum=(len*maxEl);
                
               
            }
        }

            i++;
        }
        return dp[n];
    }
};