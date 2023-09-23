// Tc=O(N2)
// SC=O(1)
#include <iostream>
#include <vector>

using namespace std;


void SelectionSort(vector<int>&arr){
    int n=arr.size();

    for(int i=0;i<n-1;i++){

        // Don't make this , it will create confusion 
        // int minEl=arr[i];
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[minIndex]>arr[j]){
                // minEl=arr[j];
                minIndex=j;
            }
        }

        if(minIndex!=i) swap(arr[i],arr[minIndex]);
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

    SelectionSort(arr);
    cout<<"Array After Bubble Sort:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}