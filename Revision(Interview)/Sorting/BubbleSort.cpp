// Tc=O(N2)
// SC=O(1)
#include <iostream>
#include <vector>

using namespace std;

/*
-> In Bubble sort , in one traversal , the largest element will go at last 
-> In 2nd tarversal , 2nd largest element will go at its correct index, that is second last position
-> and In n-1 rounds ( All the elments are at its correct index)
-> N-1 because , if we place all the n-1 elements at its correct index , then the one last element will alreasy come at its place

*/
void bubbleSort(vector<int>&arr ){
    int n=arr.size();

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
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

    bubbleSort(arr);
    cout<<"Array After Bubble Sort:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}