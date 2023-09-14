// Problem link :https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0


//  Passing 29/30 test cases
//  For the one test case - giving that your code time complexity is O(n)
// TC=O(nlogn)
//  SC=O(1)

int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	int cnt=0;
	int st=0;
	int end=n-1;
	while(st<=end){
		int mid=(st+end)/2;
		// int mid=(2*st+(end-st))/2;
		if(arr[mid]==x) {
			cnt=1;
			int i=mid-1;
			int j=mid+1;
			
			while(i>=0 && arr[i]==x){
				cnt++;
				i--;

			}

			while(j<n && arr[j]==x){
				cnt++;
				j++;
			}

			//  *** u forgot to add this break statement and for that reason , it was going in the infinte loop
			break;
		}

		else if(arr[mid]>x){
			end=mid-1;
		}
		else {
			st=mid+1;
		}

	}

	if(cnt==0) return 0;
	else return cnt;

}

/*
n=7
x=3
          st end
1 1 1 2 2 3 3 
0 1 2 3 4 5 6
i=mid-1;
j=mid+1
cnt=1;
while(i>=0 && arr[i]==x){
	cnt++;
	i--;
}

while(j<n && arr[j]==x){
	cnt++;
	j++;
}


while()
mid=3,4,5


*/