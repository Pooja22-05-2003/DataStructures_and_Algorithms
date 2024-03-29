/*
1. In que , its said that we can remove m number of element and after removal, the memory utlized by the remaing processors should be min.
2. And we can remove continous m elemnts only.
3. So try to remove the maximum time consuming process.
4. So, find the max subarray sum  of window size m
5. return total sum-maxsubarray sum

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<long long> v{10,4,8,13,20};
	int m=2;
//minium memory sum is to be returned so maximum sum contigious subarray of size m is to be removed
  int i=0,j=0;
  int curr_window_sum=0,total_sum=0;
  int maximum_subarray_sum=0;
  total_sum=accumulate(v.begin(),v.end(),0);

  // while maintaining th window size ==m , we are trying to find the max subarray sum of m size,[Uisng sliding window]
  while(j<v.size())
  {
  	curr_window_sum+=v[j];
  	
  	if(j-i+1==m)
  	{
  		maximum_subarray_sum=max(maximum_subarray_sum,curr_window_sum);
  		curr_window_sum=curr_window_sum-v[i];
  		i++;
  		// cout<<curr_window_sum<<endl;
  	}
  j++;
  }
  //cout<<maximum_subarray_sum<<endl;
  cout<< total_sum-maximum_subarray_sum;
  
}

// output is 22