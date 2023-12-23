/*
Approach :
-> First analyze the problem, it want minimum distance between any 2 points, that is only possible with the 
adjacent elements of sorted array.
-> Then sort the array.
-> Find the range of the answer. ( Min dist possible=0) and maximum distance possible(Largest Dist-Smallest Dist)
-> Then using check function and Binary Search ...find the maximum possible value of the aswer.
-> Pattern would be TTTTTTTTFFFFFFf

*/

// TC=O(log(n*(Max_el-Min_el)))
// SC=O(1)
#include<bits/stdc++.h>
using namespace std;
bool check(int mid,int k,vector<int>arr,int n){
//    We need to find k points such that there min diff >=g(mid)
    int st=arr[1];
    int cnt=0;
    for(int i=1;i<=n;i++){
        int diff= abs(st-arr[i]);
        if(diff>=mid){
            cnt++;
            st=arr[i];
        }
        else {

        }
    }

    // here cnt+1 because (1 point is already selected ) , so initilaized cnt=1 or do here cnt+1
    if(cnt+1>=k) return true;
    else return false;
}
int  solve( vector<int> arr , int n , int k){
    // Asnwer will lie in some range
    int st=0;  // minimum difference possible is between same elements
    int end=arr[n-1]-arr[0];
    bool found=false;
    int ans=0;
    while(st<=end && !found){
        int mid=(st+end)/2;
        if(check(mid,k,arr,n)==true && check(mid+1,k,arr,n)==false){
            ans=max(ans,mid);
            found=true;
        }
        else if(check(mid,k,arr,n)==true &&  check(mid+1,k,arr,n)==true){
            st=mid+1;
        }
        else {
            end=mid;
        }
    }
    return ans;
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
5
3
1 4 2 9 8

// output1:
3


// input 2 :


// output 2:


input3:


output3:


*/

