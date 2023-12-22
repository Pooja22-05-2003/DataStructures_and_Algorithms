//❌❌❌❌NOT GIVING CORRECT OUTPUT - only giving 0 as answer.
#include<bits/stdc++.h>
using namespace std;

bool check( vector<int> arr , int st,int sum,int move){
    int i=1;
    int n=arr.size();
    int cnt=0;
    while(i<=n){
        if(arr[i]%st!=0){
            cnt+=(arr[i]/st)+1;
        }
        else {
            cnt+=(arr[i]/st);
        }
        i++;
    }

    if(cnt<=move) return true;
    return false;

}
int solve(vector<int> arr,int n , int move){
    int st=1;
    int sum=0;
    int max_el=-1;
    for(int i=1;i<=n;i++){
        sum+=arr[i];
        max_el=max(max_el,arr[i]);
    }
    int end=max_el;
    int ans=0;

     int y=0;
    while(st<=end && y==0){


    // FFFFFFTTTTT(so here we need to find the first occurrence of T)..using binary search.

    //     if(check(st,sum,move)==true){
    //         ans=st;
    //         break;
    //     }
    //     else {
    //         st++;
    //     }
    // }
   
    int mid=(st+end)/2;

    if((check(arr,mid,sum,move)==true)){
        if(mid==1){
            ans=1;
            y=1;
          
        }
        else 
        if(check(arr,mid-1,sum,move)==false){
            ans=mid;
            y=1;
        }
        else end=mid-1;
    }
    else st=mid+1;


    return ans;
   }

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********
	int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> arr1(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }

    cout<<solve(arr1,n,k)<<endl;
	return 0;
}
	


/*
// input1 :

4
5
4 3 2 7

// output1:



// input 2 :
3
4
1 2 3

// output 2:

*/

