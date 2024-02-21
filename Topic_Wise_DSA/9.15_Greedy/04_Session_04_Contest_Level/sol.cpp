/*
Approach:

1. We need to convert this binary array in such a form , that no subarray of size >=k, have average 1.
2. Any subarray of size x , have average 1, if all the numbers in that subarray is 1.
3. Make the window of size k, and off the last bit, of that subarray of that window size.
4. Why are we are only , setting last 1->0 and not any other index.=? Because we need to return 
the minimum number of flips.
5. If we make the last bit 1->0, it will helpe in future subarray also.


*/

// TC=O(n*k)
// SC=O(1)

#include <bits/stdc++.h>
using namespace std;
int main() {
	
	int t;
	cin>>t;

	while(t--)
	{
		int n,k;
		cin>>n>>k;

		vector<int>arr(n+1);
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
		}

		// no subarray of size k , should have k contingous 1.
		int ans=0;
		int i=1;
		int sum=0;
		while(i<=k-1)
		{
			sum+=arr[i];
			i++;
		}

		while(i<=n)
		{
			sum+=arr[i];

			if(sum>=k)
			{
				// make the last 1 -> 0
				arr[i]=0;

				// we off the last bit, so reduce the sum
				sum--;
				ans++;

			}
			sum-=arr[i-(k)+1];
			
			i++;
		}

		cout<<ans<<endl;
	}
}


/*
Input :
2
5 5
1 1 1 1 1
4 2
1 0 1 1


Output :
1

There are two test cases:

First test case: Since all the elements are initially 1 so only subarray of size 5 has average 1. If we can flip any element from 1 to 0, the array will be [0,1,1,1,1] (After flipping first element) , the average is now .8 for subarray of size 5 which is not equal to 1. So by flipping 1 element we can acheive the goal.

Second test case: Initially array is [1 0 1 1] and K=2, so after the operations are performed no subarray of size 2,3 and 4 should have average equal to 1. If we flip 4th element array becomes, [1 0 1 0] which satisfies the above property. So again answer is 1. Note that initially subarray [1,1] had average 1.


*/