#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> arr , int x){
    int index=-1;
    int st=0;
    int end=arr.size()-1;

    while(st<=end ){
        int mid=(st+end)/2;
        if(arr[mid]>x){
            index=mid;
            end=mid-1;
        }
        else {
            st=mid+1;
        }
    }
    return index;
}

int LowerBound(vector<int> arr , int x){
    int index=-1;
    int st=0;
    int end=arr.size()-1;

    while(st<=end){
        int mid=(st+end)/2;
        if(arr[mid]>=x){
          
            end=mid-1;
        }
        else {
            index=mid;
            st=mid+1;
        }
    }
    return index;
}

int main()
{

    //**********

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //*********

    int n;
    cin >> n ;
    // cout<<"Enter elements in sorted fashion"<<endl;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<"Upper Bound (x) : "<<upperBound(arr,x)<<" Lower Bound of x : "<<LowerBound(arr,x)<<endl;
}