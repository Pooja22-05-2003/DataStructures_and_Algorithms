// Best Case Complexity - In Quicksort, the best-case occurs when the pivot element is the middle element or near to the middle element. The best-case time complexity of quicksort is O(n*logn).
// Average Case Complexity - It occurs when the array elements are in jumbled order that is not properly ascending and not properly descending. The average case time complexity of quicksort is O(n*logn).
// Worst Case Complexity - In quick sort, worst case occurs when the pivot element is either greatest or smallest element. Suppose, if the pivot element is always the last element of the array, the worst case would occur when the given array is sorted already in ascending or descending order. The worst-case time complexity of quicksort is O(n2).
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>&arr,int st, int end){
    int pivot=arr[end];
    int i=st-1; // i is telling how many elements are smaller then pivot element

    for(int j=st;j<=end-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[end]);
    return i+1;
}
void QuickSort(vector<int>&arr,int st, int end){

        if(st<end){
        int pivot=partition(arr,st,end);
        QuickSort(arr,st,pivot-1);
        QuickSort(arr,pivot+1,end);
        }
        
    
}
void QuickSort(vector<int>&arr){
    return QuickSort(arr,0,arr.size()-1);
}
int main(){
    
    int size;
    cout<<"Enter size of the array:"<<endl;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Array before  Sort:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    QuickSort(arr);
    cout<<"Array After Bubble Sort:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}