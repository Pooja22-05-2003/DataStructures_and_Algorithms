/*
Approach:
Observation:-> First element of Array A = First element of Array B if it is not 
happening then for sure you need to bring some element in Array B at the start 
position which will be equal to Array A element -> you can do this operation 
right now or after some operations but it is guaranteed that you will have to
 do it 


-> Now the problem has changed to find the largest subarray in Array A which is 
coming as a subset in Array B

-> our answer would be (n-cnt) 
*/
// TC=O(n3) 
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>arr1 , vector<int> arr2 , int i,int j ,int n){
    int prev_ind=-1;
    for(int a=i;a<=j;a++){
        for(int b=1;b<=n;b++){
            if(arr2[b]==arr1[a]){
                if(b>prev_ind){
                    prev_ind=b;
                    break;
                }
                else return false;
            }
        }
       
    }

    return true;

}
int solve(vector<int> arr1, vector<int>arr2,int n){
    int maxLen=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            // cout<<"i:"<<i<<" j:"<<j<<"check?:"<<check(arr1,arr2,i,j,n)<<endl;
            if(check(arr1,arr2,i,j,n)){
                
                maxLen=max(maxLen,(j-i+1));
            }
        }
    }
    return (n-maxLen);
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

    vector<int> arr1(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }

    vector<int> arr2(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr2[i];
    }
    cout<<solve(arr1,arr2,n)<<endl;
	return 0;
}
	


/*
// input1 :
6
4 2 3 1 5 6 
3 1 4 6 5 2


// output1:
3 (from index 3 to 5= subarray 3 1 5)


// input 2 :

// output 2:



*/
