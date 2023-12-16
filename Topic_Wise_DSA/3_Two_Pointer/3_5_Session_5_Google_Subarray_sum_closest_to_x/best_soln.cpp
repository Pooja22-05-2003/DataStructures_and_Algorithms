/*
Otpmized  approach.

As we are starting from 1 to j1, then again from 2 to j1, we can use two pointer 
and can use the previous sum in our current answer.


*/

// TC=O(n) 
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &b,int n , int k ){
    int i = 1 ;
    int j = 1 ;
    int ans=0;
    int sum=0;
    while(i<=n && j<=n){
        if(i==j){
            if(b[i]>k){
                i++;
                j++;
                if(j<=n) sum+=b[j];
            }
            else{
                int len=1;
                ans=max(ans,len);
                j++;
                if(j<=n){
                    sum+=b[j];
                }
            }
        }
        else {
            if(sum>k){
                // it means i to j-1 is surely valid
                ans=max(ans,((j-1)-i+1));

                //  now u have considered i to j-1

                // i-1 to j-1 is surely smaller than equal to k
                sum-=b[i];
                i++;
                
                j++;
                if(j<=n){
                    sum+=b[j];
                }

            }
            else {
                j++;
                if(j<=n){
                    sum+=b[j];
                }
                
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
