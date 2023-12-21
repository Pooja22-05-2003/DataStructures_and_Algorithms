class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();

        int st=0;
        int end=n-1;
        while(st<=end){
        int mid=(st+end)/2;
        // check the condition whether st---mid (is sorted or not)
        if(arr[mid]==target) return mid;
        if(arr[st]<=arr[mid]){
            // now check whether the target lie in that range or not
            if(target>=arr[st] && target<arr[mid]){
                end=mid-1;

            }
            else st=mid+1;
        }
        else {
            if(target>arr[mid] && arr[end]>=target) {
                st=mid+1;
            }
            else {
                end=mid-1;
            }
        }

        }
        return -1;
    }
};