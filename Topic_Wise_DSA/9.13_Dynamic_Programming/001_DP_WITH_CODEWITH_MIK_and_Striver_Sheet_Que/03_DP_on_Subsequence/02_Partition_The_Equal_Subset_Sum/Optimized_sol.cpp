// I missed the 2 edge case and got runtime error because of that., so keep in mind in future.

class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
  
    
    vector<bool>prev(k+1,false);
    if(arr[0]<=k) prev[arr[0]]=true; // ⚠️⚠️⚠️ This edge case u are missing , and u are accessing the outof bound element , let's say your k value is 5 , and arr size is 1 and its el=100 how u can acees prev[100], because the prev arr size is even not that
    prev[0] =true;
    for(int ind=1;ind<=n-1;ind++) // ⚠️⚠️we will intialize this only from ind=1, because at ind=0, only the base the which we initialized is true
    {
        prev[0]=true;
        vector<bool>temp(k+1,false);
        for(int target=1;target<=k;target++)
        {
            bool notTake=prev[target];
            bool Take=false;
            if(arr[ind]<=target)
             {
               Take=prev[target-arr[ind]];
             }
            temp[target]=(notTake | Take);
        }
        prev=temp;
    }

    return prev[k];
}
    bool canPartition(vector<int>& nums) {
        int total=0;
        if(nums.size()==1) return false; // ⚠️⚠️Must handle this edge case
        for(auto it : nums) total+=it;
        if(total%2!=0) return false;
        int n=nums.size();
        return subsetSumToK(n,total/2,nums);
        
    }
};