// brute force approach

// TC=O(N3)
// SC=O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=INT_MIN;
        int n=nums.size();
        for(int  i=0;i<n;i++){
            for(int  j=i+1;j<n;j++){
                for(int k=j+1 ; k<n ;k++){
                    if(((long long)(nums[i] - nums[j]) * nums[k])>ans){

                        // put long long in bracket , else it would give error
                        long long temp=(long long)(nums[i] - nums[j]) * nums[k];
                        ans=max(ans,temp);
                    }
                }
            }
        }
        // cout<<"ans:" << ans<<endl;
        if(ans>0) return ans;
        else return 0;
    }
};


