// O(n2)
// sc=O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n+1,1);
        int i=2;
        while(i<=n){

            int j=i-1;
            while(j>=1){
                if(arr[j-1]<arr[i-1]) dp[i]=max(dp[i],1+dp[j]);
                j--;
            }
            
            i++;
        }
        
        // rerturn max of all dp[i]
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;

    }
};