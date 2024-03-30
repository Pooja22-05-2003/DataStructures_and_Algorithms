// Memoization code
// TC=O(n)
// SC=(n*3)


#include <bits/stdc++.h>
using namespace std;
int solve(int ind, int prev,vector<vector<int>> &points,vector<vector<int>>&dp )
{
	// base case
	if(ind==points.size()) return 0;
	int ans=INT_MIN;

	if(dp[ind][prev]!=-1) return dp[ind][prev];
	if(prev==3)
	{
		// it means we can pick any of the three activity
		ans=max(ans,(points[ind][0]+ solve(ind+1,0,points,dp)));
		ans=max(ans,(points[ind][1]+ solve(ind+1,1,points,dp)));
		ans=max(ans,(points[ind][2]+solve(ind+1,2,points,dp)));
	

	}
	else if (prev==0)
	{
        ans=max(ans,(points[ind][1]+ solve(ind+1,1,points,dp)));
		ans=max(ans,(points[ind][2]+ solve(ind+1,2,points,dp)));
	}
	else if (prev==1)
	{
		ans=max(ans,(points[ind][0]+solve(ind+1,0,points,dp)));
		ans=max(ans,(points[ind][2]+ solve(ind+1,2,points,dp)));
	}
	else if(prev==2)
	{
		ans=max(ans,(points[ind][0]+solve(ind+1,0,points,dp)));
		ans=max(ans,(points[ind][1]+solve(ind+1,1,points,dp)));
	}
	return dp[ind][prev]= ans;
	
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
	vector<vector<int>>dp(n,vector<int>(4,-1));
	return solve(0,3,points,dp);
}