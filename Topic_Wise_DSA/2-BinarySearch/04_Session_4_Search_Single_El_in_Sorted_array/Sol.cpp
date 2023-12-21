// TC=O(logn)
// SC=O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int st=0;
        int end=arr.size()-1;
        int n=arr.size();

        //  if (arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid]
        // pattern :- if even ind element == odd index element [it means that our ans lie in right part of the array]
        // patter:- if odd ind element == even ind element [it means that our ans lie on the left part of the array]
        if(n==1) return arr[0];
        // ✨ To prevent the edge cases we will put our st=1 and end =n-2
        if(arr[0]!=arr[1]) return arr[0];
        if(arr[n-1]!=arr[n-2]) return arr[n-1];
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];

            if(((mid%2)==0 && arr[mid+1]==arr[mid]) || ((mid%2)!=0 && arr[mid-1]==arr[mid]))  st=mid+1;
            else end=mid-1;
            
        }
        return -1;
    }
};