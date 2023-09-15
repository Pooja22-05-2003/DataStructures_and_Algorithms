//  TC=O(n*k)
//  SC=2*O(n)

int mod=(1e9+7);

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n=arr.size();
	// vector<vector<int>> dp(n,vector<int>(k+1,0));
	vector<int>prev(k+1,0);
	prev[0]=1;
	if(arr[0]<=k) prev[arr[0]]=1;

	


	for(int ind=1;ind<n;ind++){
		vector<int> curr(k+1,0);
		curr[0]=1;
		for(int target=1;target<=k;target++){
				int include=0;

	           if(arr[ind]<=target){
		             include=prev[target-arr[ind]];
	             }

	             int exclude=prev[target];

	// ⚠️⚠️ First convert mod to int then do the operation
	        curr[target]=(include+exclude)%(mod);
		}
		prev=curr;
	}
	return prev[k];
}






