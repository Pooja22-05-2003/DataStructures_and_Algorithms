// TC=O(n2)
// SC=O(n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    int n=arr.size();
    vector<int>dp(n,1);
	// dp[i][j]=> It will denote the longest subsequence when the last element in the subsequence is index i element.

	vector<int>hash(n,0);
	int i=1;
	while(i<n)
	{
		// int lastindex=i;
		hash[i]=i;
		int j=i-1;
		while(j>=0)
		{
			if((arr[i]%arr[j]==0) && (1+dp[j]>dp[i]))
			{
				dp[i]=max(dp[i],1+dp[j]);
				hash[i]=j;
			}
            j--;
		}
		cout<<"i:"<<i<<" dp[i]:"<<dp[i]<<endl;
		i++;
	}

    // return the maximum length among all the indexes.
	// cout<<"Hash array:"<<endl;
	// for(auto it : hash) cout<<it<<",";
	// cout<<endl;
    int len=0;
	int lastindex=-1;
    for(int i=0;i<n;i++)
    {
       if(dp[i]>len)
	   {
		   len=dp[i];
		   lastindex=i;
	   }
		
    }
	// cout<<"len:"<<len<<","<<"lastindex:"<<lastindex<<endl;

	vector<int> ans;

	// ans.push_back(arr[lastindex]);
	while(hash[lastindex]!=lastindex)
	{		
		// cout<<"lastindex:"<<lastindex<<"arr[lastindex]:"<<arr[lastindex]<<endl;
		ans.push_back(arr[lastindex]);
		lastindex=hash[lastindex];
		
		
	}
	
    // return len;
	ans.push_back(arr[lastindex]);
	sort(ans.begin(),ans.end());

	return ans;
    }
};