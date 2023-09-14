/*
problem link :https://www.codingninjas.com/studio/problems/lower-bound_8165382?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/

// TC=O(logn)
// sc=O(1)

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int st=0;
	int end=n-1;
	int ind=n;


/*
1 2 2 3 3 5
0 1 2 3 4 5
el=0

ind=1
mid=2


*/
	while(st<=end){
		//  here u are doing previously wrong 
		//  u are doign mid=(st+(end-st))/2 which is wrong ❌
		int mid=(2*st+(end-st))/2;
		if(arr[mid]>=x){
			ind=mid;
			end=mid-1;

        }

        else {
            st = mid + 1;
         }
    }

	return ind;

	
}

// ind=-1,2,2
// el=2

// 1 2 2 3 3 5
// 0 1 2 3 4 5




// mid=2
// 2