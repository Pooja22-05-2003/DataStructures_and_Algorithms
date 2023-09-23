// Best Case Complexity: The merge sort algorithm has a best-case time complexity of O(n*log n) for the already sorted array.

// Average Case Complexity: The average-case time complexity for the merge sort algorithm is O(n*log n), which happens when 2 or more elements are jumbled, i.e., neither in the ascending order nor in the descending order.

// Worst Case Complexity: The worst-case time complexity is also O(n*log n), which occurs when we sort the descending order of an array into the ascending order.

// Space Complexity: The space complexity of merge sort is O(n).
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Merge(vector<int>&arr,int st,int mid, int end){

    

    int a[arr.size()];
    int i=st;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            a[k]=arr[i];
            i++;
            k++;
        }
        else{
            a[k]=arr[j];
            j++;
            k++;
        }
    }


    while(i<=mid){
        a[k]=arr[i];
            i++;
            k++;
    }

    while(j<=end){
         a[k]=arr[j];
            j++;
            k++;
    }

    int p=0;
    for(int ind=st;ind<=end;ind++){
        arr[ind]=a[p];
        p++;
    }

}
void mergesort(vector<int>&arr,int st, int end){
    if(st>=end ) return ;

        int mid=(st+end)/2;
        mergesort(arr,st,mid);
        mergesort(arr,mid+1,end);
        Merge(arr,st,mid,end);
    
}
void MergeSort(vector<int>&arr){
    return mergesort(arr,0,arr.size()-1);
}
int main(){
    
    int size;
    cout<<"Enter size of the array:"<<endl;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Array before Bubble Sort:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    MergeSort(arr);
    cout<<"Array After Bubble Sort:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}