// Tc=O(logn)
// SC=O(1)

#include <iostream>
#include <vector>

using namespace std;
int binarySearch(vector<int> &arr,int el){
    int n=arr.size();

    int leftIndex=0;
    int rightIndex=n-1;

    while(leftIndex<=rightIndex){
        int mid=(leftIndex+rightIndex)/2;
        if(arr[mid]==el) return mid;
        else if(arr[mid]>el) rightIndex=mid-1;
        else leftIndex=mid+1;
    }

    return -1;

}
int main(){
    
    int size;
    cout<<"Enter size of the array:"<<endl;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Enter element u want to search:"<<endl;
    int el;
    cin>>el;
    int ind=binarySearch(arr,el);
    if(ind!=-1) cout<<"Element found at index:"<<ind<<endl;
    else cout<<"Element not found in the array"<<endl;


    return 0;
}