// using prefix concept;
//  Time Complexity =O(N2)
//  Space Complexity =O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long ans=INT_MIN;
        vector<int> prefix(n,INT_MIN);
        for(int i=1;i<=n-1;i++){
            int prev=prefix[i-1];
            int maxx=INT_MIN;
            int j=i-1;
            while(j>=0){
                int diff=nums[j]-nums[i];
                prefix[i]=max(prev,max(maxx,diff));
                maxx=max(maxx,diff);
                j--;
            }
            
           
        }
        
//          loop for calculation of (nums[i] - nums[j]) * nums[k])
        if(n>=3){
//              our prefix[i-1] will contain the maximum value of (nums[i]-nums[j])
            for(int k=2;k<=n-1;k++){
            long long val=(long long) (prefix[k-1]) * (long long) (nums[k]);
            ans=max(val,ans);
            }
            
            return (ans==INT_MIN  || ans<0) ? 0:ans;
        }
        else return 0;
        
    }
};