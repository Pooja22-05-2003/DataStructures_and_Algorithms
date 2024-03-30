// Recursive Code
// TC=O(3^n)
// SC=(n)


#include <bits/stdc++.h>
using namespace std;
int solve(int ind, int prev,vector<vector<int>> &points )
{
	// base case
	if(ind==points.size()) return 0;
	int ans=INT_MIN;
	if(prev==3)
	{
		// it means we can pick any of the three activity
		ans=max(ans,(points[ind][0]+ solve(ind+1,0,points)));
		ans=max(ans,(points[ind][1]+ solve(ind+1,1,points)));
		ans=max(ans,(points[ind][2]+solve(ind+1,2,points)));
	

	}
	else if (prev==0)
	{
        ans=max(ans,(points[ind][1]+ solve(ind+1,1,points)));
		ans=max(ans,(points[ind][2]+ solve(ind+1,2,points)));
	}
	else if (prev==1)
	{
		ans=max(ans,(points[ind][0]+solve(ind+1,0,points)));
		ans=max(ans,(points[ind][2]+ solve(ind+1,2,points)));
	}
	else if(prev==2)
	{
		ans=max(ans,(points[ind][0]+solve(ind+1,0,points)));
		ans=max(ans,(points[ind][1]+solve(ind+1,1,points)));
	}
	return ans;
	
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
	
	return solve(0,3,points);
}