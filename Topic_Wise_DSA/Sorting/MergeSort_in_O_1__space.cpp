// Tc=O(N2)
// SC=O(1)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2) {
//     if (arr1[ind1] > arr2[ind2]) {
//         swap(arr1[ind1], arr2[ind2]);
//     }
// }
// void merge(vector<int> &arr1, vector<int > &arr2, int n, int m) {
//     // len of the imaginary single array:
//     int len = n + m;

//     // Initial gap:
//     int gap = (len / 2) + (len % 2);

//     while (gap > 0) {
//         // Place 2 pointers:
//         int left = 0;
//         int right = left + gap;
//         while (right < len) {
//             // case 1: left in arr1[]
//             //and right in arr2[]:
//             // if (left < n && right >= n) {
//             //     swapIfGreater(arr1, arr2, left, right );
//             // }
//             // // case 2: both pointers in arr2[]:
//             // else if (left >= n) {
//             //     swapIfGreater(arr2, arr2, left , right);
//             // }
// 			// // case 3: both pointers in arr1[]:
//             // else {
//             //     swapIfGreater(arr1, arr1, left, right);
//             // }
//             if (arr1[left] > arr2[right]) {
//              swap(arr1[left], arr2[right]);
//     }
//             left++, right++;
//         }
//         // break if iteration gap=1 is completed:
//         if (gap == 1) break;

//         // Otherwise, calculate new gap:
//         gap = (gap / 2) + (gap % 2);
//     }
// }




void merge(vector<int> &arr1, vector<int > &arr2, int n, int m) {
  int len=(n+m);
  int gap=(len/2) + (len%2);

  while(gap>0){

    int left=0;
    int right=left+gap;
    while(right<len){
    if(arr1[left]>arr2[right]) swap(arr1[left],arr2[right]);
    left++;
    right++;
    }
    if(gap==1) break;
    gap=(gap/2)+(gap%2);
  }
      
}
void Merge(vector<int>&arr,int st,int mid, int end){

    // int len=end-st+2;
    // int gap=(len/2) +(len%2);

    // while(gap>0){
    //     int left=st;
    //     int right=st+gap;

    //     while(right<len){
    //         if(arr[left]>arr[right]){
    //             swap(arr[left],arr[right]);
    //         }
    //         left++;
    //         right++;
    //     }


    //     if(gap==1) break;
    //     int gap=(gap/2) +(gap%2);
    // }


      merge(arr,arr,(((mid)-st+1)),((end-(mid+1)+1)));

}
void mergesort(vector<int>&arr,int st, int end){
    
        if(st<end){
        int mid=(st+end)/2;
        mergesort(arr,st,mid);
        mergesort(arr,mid+1,end);
        Merge(arr,st,mid,end);
        }
 
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