// Tc=O(logn)
// SC=O(1)

#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> &arr,int el,int leftIndex,int rightIndex ){
    int n=arr.size();

 
    //  ** Here in recursive algo , while loop will not work , u need to write if, (else it will go in the infinte loop)

    if(leftIndex<=rightIndex){
        int mid=(leftIndex+rightIndex)/2;
        if(arr[mid]==el) return mid;
        //  here in the below else if and else condition , u are calling the recursion and u are not returnign anything , it will not return anything, and always return that element not found
        else if(arr[mid]>el) return binarySearch(arr,el,leftIndex,mid-1);
        else return binarySearch(arr,el,mid+1,rightIndex);;
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
    int ind=binarySearch(arr,el,0,size-1);
    if(ind!=-1) cout<<"Element found at index:"<<ind<<endl;
    else cout<<"Element not found in the array"<<endl;


    return 0;
}