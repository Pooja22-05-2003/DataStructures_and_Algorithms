// Case	Time Complexity
// Best Case
// O(n)
// Average Case
// O(n2)
// Worst Case
// O(n2)

//  SC=O(1)
#include <iostream>
#include <vector>

using namespace std;


void InsertionSort(vector<int>&arr){
    int n=arr.size();

    //  we basically divide our array in 2 parts, one is sorted and other is unosorted,
    //  Pick the one unsorted element from the unsorted pool and find its correct index in the sorted ppol
    // By swapping and place the current index at its correct position


//  4 3 1 2 5
//  1 2 3 4 5
//  curr=3
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int j=i-1;
        for(j;j>=0;j--){
            if(curr<arr[j]){
                // right shift
                arr[j+1]=arr[j];
            }
            else {
                break;
            }
        }

        swap(arr[j+1],curr);
    }
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

    InsertionSort(arr);
    cout<<"Array After Bubble Sort:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}