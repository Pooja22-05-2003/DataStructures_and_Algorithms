// Tc=O(N2)
// SC=O(1)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Merge(vector<int>&arr,int st,int mid, int end){

    int i=mid;
    int j=mid+1;

    while(i>=0 && j<=end){
        if(arr[i]>arr[j]) swap(arr[i],arr[j]);
        else break;
        i--;
        j++;
    }
    sort(arr.begin()+st,arr.begin()+mid+1); 
    sort(arr.begin()+mid+1,arr.begin()+end+1);

   

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