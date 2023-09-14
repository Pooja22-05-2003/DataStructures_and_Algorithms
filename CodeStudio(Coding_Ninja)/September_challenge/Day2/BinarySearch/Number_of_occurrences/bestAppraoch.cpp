//  Passed all the test cases
//  We can also solve this question  using first ans last occurence same .
//  TC=O(2nlogn)
//  SC=O(1)
    int FirstOccurence(vector<int>& arr,int target){
        int ans=-1;
        int st=0;
        int end=arr.size()-1;

        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]==target){
                ans=mid;
                end=mid-1;
            }
            else if(arr[mid]>target){
                
                end=mid-1;
            }

            else {
                st=mid+1;
            }
        }

        return ans;
    }

    int LastOccurence(vector<int>& arr,int target){
        int ans=-1;
        int st=0;
        int end=arr.size()-1;

        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]==target){
                ans=mid;
                st=mid+1;
                
            }

            // ⚠️⚠️⚠️😶‍🌫️😶‍🌫️ here u wrote the opposite sign for this
            else if(arr[mid]<target){
                st=mid+1;
            }

            else {
               end=mid-1;
            }
        }

        return ans;
    }
	
	pair<int,int> FirstAndLastOccurence(vector<int>& arr, int n, int x){
		int firstAns=FirstOccurence(arr,x);
		int secondAns=LastOccurence(arr,x);
		return {firstAns,secondAns};
	}
	

int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	pair<int,int> temp=FirstAndLastOccurence(arr,n,x);

	// if the first or the last occurrence , any one of them is -ve , it means that that element is not present in our array
	if(temp.first==-1) return 0;

	// ⚠️⚠️ here u need to add +1 also , because the array are 1based indexing
	else return temp.second-temp.first+1;
	
}
