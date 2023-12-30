/*
Otpmized  approach.

✨✨ Similar to previous question  (just replace sum with d=b[j]-b[i])
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
    int d=0;
    while(i<=n && j<=n){
        if(i==j){
             d = b[j] - b[i] ;
            if(d>k){
                i++;
                j++;
                if(j<=n)  d = b[j] - b[i] ;;
            }
            else{
                int len=1;
                ans=max(ans,len);
                j++;
                if(j<=n){
                    d = b[j] - b[i] ;;
                }
            }
        }
        else {
             d = b[j] - b[i] ;
            if(d>k){
                // it means i to j-1 is surely valid
                ans=max(ans,((j-1)-i+1));

                //  now u have considered i to j-1

                // i-1 to j-1 is surely smaller than equal to k
                 
                i++;
                
                j++;
                if(j<=n){
                     d = b[j] - b[i] ;
                }

            }
            else {
                j++;
                if(j<=n){
                     d = b[j] - b[i] ;
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
5
3
1 2 3 4 8


// output1:
4(len from 1 to 4)




*/