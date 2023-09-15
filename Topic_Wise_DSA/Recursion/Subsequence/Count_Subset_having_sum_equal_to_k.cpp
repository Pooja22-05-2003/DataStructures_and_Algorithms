#include <bits/stdc++.h>
using namespace std;


int  printSumK(int ind , int arr[] , int n, vector<int> & ds ,int k , int currSum){

    // base case
    if(ind==n){

        if(currSum==k){
        //print the subsequence
        // for (auto it : ds) {
        //     cout<<it<<" ";
        // }

       
        // cout<<endl;
        return 1;
        }
         else return 0;
    }

    // take 
    ds.push_back(arr[ind]);
    currSum+=arr[ind];
    int  l=(printSumK(ind+1 , arr, n , ds ,k, currSum)) ;
    // not take
    ds.pop_back();  
    currSum= currSum-arr[ind];
    int r=(printSumK(ind+1 , arr, n , ds , k,currSum )) ;

    return l+r;
   

}


void print(int ind , int arr[] , int n, vector<int> & ds ){

    // base case
    if(ind==n){
        //print the subsequence
        for (auto it : ds) {
            cout<<it<<" ";
        }

        if(ds.size()==0) cout<<"{}"<<endl;
        cout<<endl;
        return ;
    }

    // take 
    ds.push_back(arr[ind]);
    print(ind+1 , arr, n , ds);
    // not take
    ds.pop_back();   
    print(ind+1 , arr, n , ds);

}
int main(){

    int n ;
    cout<<"Enter the size of the array :"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i<<"th elementof the array :"<<endl;     
        cin>>arr[i];
    }
    vector<int> ds;
    cout<<"Printing 1 subsequences having sum equal to k : "<<endl;
    print(0,arr,n,ds);

    cout<<"Enter k (k is the sum that you want  ) :"<<endl;
    int k;
    cin>>k;
    cout<<"Number of subsequence having sum equal to k : "<<endl;
    cout<<printSumK(0,arr,n,ds,k,0);

    return 0;
}

/*

Enter the size of the array :
3
Enter 0th elementof the array :
1
Enter 1th elementof the array :
2
Enter 2th elementof the array :
1
Printing 1 subsequences having sum equal to k :
1 2 1
1 2
1 1
1
2 1
2
1
{}

Enter k (k is the sum that you want  ) :
2
Number of subsequence having sum equal to k :
2



*/
