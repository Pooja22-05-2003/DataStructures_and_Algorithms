// Time Complexity =O(N3)
// Space Complexity =O(1)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // we will create set of vectore , so that it only contain unique quadraples.

        //  sort the array so that u will be able to apply two pointer at last
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        int size=nums.size();
        for(int i=0;i<=size-4;i++){
            long long x=target-nums[i];
            for(int j=i+1;j<=size-3;j++){
                long long  UpdatedTarget=x-nums[j];
                int m=j+1;
                int n=size-1;
                while(m<n){
                    long long sum=(nums[m]+nums[n]);
                    if(sum==UpdatedTarget){
                        vector<int>p={nums[i],nums[j],nums[m],nums[n]};
                        sort(p.begin(),p.end());
                        s.insert(p);
                        m++;
                        
                    }
                    else if(sum>UpdatedTarget){
                        n--;
                    }
                    else {
                        m++;
                    }
                }
            }
        }


        for(auto i:s){
            ans.push_back(i);
        }

        return ans;
    }
};