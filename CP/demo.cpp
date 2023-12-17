// @Karandeep Singh(Doubt Resolver) @Jindal(Dsa Doubt Solver) Sir..pls help.
// Issue : Giving incorrect output for first test case ...

// TWO POINTER (Session-7) Part-1
// Problem link : https://docs.google.com/document/d/1RrD47OfXpZwFBcJ7qJpAz6v6ow4w1GTDf3SKcm5g-oA/edit  (problem -3 of this docs)

// code : 
// // TC=O(n) 
// // SC=O(1)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &b,int n , int k ){
    int i = 1 ;
    int j = 1 ;
    int cnt=0;
    int ii;
    // int ans=0;
    int sum=0;
    while(i<=n && j<=n){
        if(i==j){
            if(b[i]>k){
                i++;
                j++;
                if(j<=n) sum+=b[j];
            }
            else{
                // int len=1;
                
                // ans=max(ans,len);
                j++;
               
                if(j<=n){
                    // cnt++;
                    sum+=b[j];
                }
                else {
                    cnt++;
                    i=n+1;
                    j=n+1;
                }
            }
        }
        else {
            if(sum>k){
                // it means i to j-1 is surely valid
   
              
                cnt+=(abs(j-1)-i)+1;
                

                //  now u have considered i to j-1

                // i+1 to j-1 is surely smaller than equal to k
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
                if(j==n+1){
                    ii=i;
                }
                
            }
        }
    }

    if(ii>=1){
        int a=ii;
        int b=n;
        int l=abs(a-b)+1;
        cnt+=(l*(l+1))/2;
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
3
10
2 5 6

explaination :
Input : arr[] = {2, 5, 6}
        K = 10
Output : 4
The subarrays are {2}, {5}, {6} and
{2, 5},



// output1:
2❌❌❌(Giving wrong ans[correct output is 4])


// input 2 :
5
10
1 11 2 3 15


{1}, {2}, {3} and {2, 3}-ans-4

// output 2:
4


*/