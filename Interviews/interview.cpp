/*
arr- integers - duplicates
- need to remove the duplicates and sort it 
*/

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>&arr,vector<int>&ans){
    set<int> s;
    for(int i=0;i<arr.size();i++){
        s.insert(arr[i]);
    }

  
    for(auto it : s){
        ans.push_back(it);
       
    }
}

int main(){
    int size;
    cout<<"Enter the size of the array :"<<endl;
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the element of the array : "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"array : "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    vector<int> ans;
    solve(arr,ans);

    cout<<"Final array : "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}