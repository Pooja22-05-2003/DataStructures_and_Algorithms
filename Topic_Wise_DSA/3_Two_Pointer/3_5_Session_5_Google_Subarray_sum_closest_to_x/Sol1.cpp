/*
Otpmized  approach.

As we are starting from 1 to j1, then again from 2 to j1, we can use two pointer 
and can use the previous sum in our current answer.


*/

// TC=O(n2) (somewhat lesser than O(n2))
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int n , int k ){
    int maxAns=INT_MIN;
    int sum=0;
    int j=0;
    for(int i=1;i<=n;i++){
        if(arr[i]>k){
            continue;
        }
        j++;
        for(;j<=n;j++){
            sum+=arr[j];
            if(sum<=k){
                maxAns=max(maxAns,(j-i+1));
            }
            else break;
        }
        sum-=arr[i];
    }
    return maxAns;
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

    int k;
    cin>>k;

    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n,k)<<endl;
	return 0;
}
	


/*
// input1 :
6
7
2 5 8 8 5 8


// output1:
2


// input 2 :
7
4
1 2 1 0 1 1 0

// output 2:
5


*/
