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
    vector<int> prefix_i_j(n+1,0);
    vector<int> suffix_k_l(n+1,0);

    for(int j=1;j<=n;j++){
        for(int i=j-1;i>=1;i--){
            if(arr[i]<arr[j]) prefix_i_j[j]=prefix_i_j[j]+1;
            else prefix_i_j[j]=1;

        }
    }

    for(int k=1;k<=n;k++){
        for(int l=k+1;l<=n;l++){
            if(arr[l]>arr[k]) suffix_k_l[k]=suffix_k_l[k]+1;
            else suffix_k_l[k]=suffix_k_l[k];
        }
    }
    int ans=0;
    for(int j=1;j<=n;j++){
        for(int k=j+1;k<=n;k++){
            if(arr[j]<arr[k]){

                // here ind  j will come not j-1 and similarly k will come not k+1
                int cnt=prefix_i_j[j]*suffix_k_l[k];
                ans+=cnt;
            }
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
5
1 2 3 4 5 


// output1:
5


// input 2 :


// output 2:

*/
