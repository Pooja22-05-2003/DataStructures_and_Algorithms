#include <bits/stdc++.h>
using namespace std;

void Power_set(int ind , string s , int n, vector<int> & ds ){

// on is also empty string 
  cout<<"''"<<endl;
  for(int num=0 ; num<pow(2,n) ; num++){
    string subsequence="";
  
    for(int i=0;i<n;i++){
        if(num & (1<<i)){
         
            subsequence+=(s[i]);
        }
        
    }
    cout<<subsequence<<endl;

  }

}
int main(){

    // int n ;
    // cout<<"Enter the size of the array :"<<endl;
    // cin>>n;
    // int arr[n];

    string s;
    cout<<"Enter string :"<<endl;
    cin>>s;
    // for(int i=0;i<n;i++){
    //     cout<<"Enter "<<i<<"th elementof the array :"<<endl;     
    //     cin>>arr[i];
    // }
    vector<int> ds;
    cout<<"Printing all the subsequences : "<<endl;
    Power_set(0,s,s.size(),ds);

    return 0;
}

/*


Enter the size of the array :
Enter string :
abc
Printing all the subsequences :
''

a
b
ab
c
ac
bc
abc


*/