#include <bits/stdc++.h>
using namespace std;

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
    cout<<"Printing all the subsequences : "<<endl;
    print(0,arr,n,ds);

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
3
Printing all the subsequences : 
1 2 3 
1 2 
1 3 
1 
2 3
2
3
{}


*/