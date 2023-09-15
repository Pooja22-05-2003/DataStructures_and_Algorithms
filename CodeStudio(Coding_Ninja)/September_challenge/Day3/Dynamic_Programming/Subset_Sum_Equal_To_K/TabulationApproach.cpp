//  Problem Link :https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
// Space Optimization- O(n*k)
// Space Complexity = O(n*k)

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // if (n == 0) return k == 0;
    // vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    vector<bool>prev(k+1,false);
    
     //   ⚠️⚠️⚠️ dont' forget to intialize curr[0]=true, in space optimization
    prev[0]=true;

    if(arr[0]<=k) prev[arr[0]] =true;


    for(int ind=1;ind<n;ind++){

          //   ⚠️⚠️⚠️ make sure to make this curr vector inside
        vector<bool>curr(k+1,false);

         //   ⚠️⚠️⚠️ dont' forget to intialize curr[0]=true, in space optimization
        curr[0]=true;
        for(int target=1;target<=k;target++){
        bool take = false;

        //   ⚠️⚠️⚠️ take condition is only applicable if the current element is greater or equal to target, u missed this codition
        if (arr[ind] <= target) {
          take = prev[target - arr[ind]];
        }

        //  not take
        bool notTake = false;
        notTake = prev[target];

        curr[target] = take || notTake;
        }
        prev=curr;

       
    }
   
     return prev[k];
}
