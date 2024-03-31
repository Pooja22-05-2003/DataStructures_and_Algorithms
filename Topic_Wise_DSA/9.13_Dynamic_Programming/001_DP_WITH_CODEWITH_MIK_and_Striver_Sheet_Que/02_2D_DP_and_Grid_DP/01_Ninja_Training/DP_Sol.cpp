// TC=O(n)
// SC=O(n*3)

int ninjaTraining(int n, vector<vector<int>> &nums)
{
    // Write your code here.
    vector<int>dp1(n,0); // it means at the ith index, nijas will do the first task
    vector<int>dp2(n,0); // do the second task for sure on the 2nd day
    vector<int>dp3(n,0);// do the third task for sure on the 3rd day

    dp1[0]=nums[0][0];
    dp2[0]=nums[0][1];
    dp3[0]=nums[0][2];

    for(int i=1;i<n;i++)
    {
        dp1[i]=max(dp1[i-2], (nums[i][0]+max(dp2[i-1],dp3[i-1])));
        dp2[i]=max(dp2[i-2], (nums[i][1]+max(dp1[i-1],dp3[i-1])));
        dp3[i]=max(dp3[i-2], (nums[i][2]+max(dp2[i-1],dp1[i-1])));
    }
    return max(dp1[n-1], max(dp2[n-1],dp3[n-1]));

}