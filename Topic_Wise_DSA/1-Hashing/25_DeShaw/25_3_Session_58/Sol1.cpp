// Soln Link : https://ideone.com/0N9aMH


/*
-> Create one prefix array , which will tell that arr from 0....i is sorted or not.
-> Similarly create one suffix array which will tell that arr from (i+1......n) is sorted or not.
-> Now using 2 for loop of subarray , check the condition which is (lets say subarray is from i....j) then check
that arr[i-1]<=arr[j+1] && prefix[i-1]==true and suffix[j+1]==true (this can be done in O(1) time ) , now u can increment the cnt.

*/

// TC=O(n2)
// SC=O(n)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int n ){
    vector<int> prefix(n+1,0);
    vector<int> suffix(n+1,0);

    prefix[1]=1;
    for(int i=2;i<=n;i++ ){
        if(arr[i]>=arr[i-1] && prefix[i-1]==1) prefix[i]=1;
    }

    suffix[n]=1;
    for(int i=n-1;i>=0 ;i--){
        if(arr[i]<=arr[i+1] && suffix[i+1]==1) suffix[i]=1;
    }


    //  subarray 
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){ 
            if((i-1)>=1 && arr[i-1]<=arr[j+1] && prefix[i-1]==1 && suffix[i+1]==1) cnt++;
        }
    }

    return cnt;

}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********


    //*********
	int n;
    cin>>n;

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n)<<endl;
	return 0;
}
	


/*
// input1 :
4
1 2 1 2


// output1:
7


// input 2 :


// output 2:

*/
