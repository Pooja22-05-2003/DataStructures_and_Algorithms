/*
Approach :
1. We are given one array and a value n (no of partition possible).
2. So divide the array into atmost n parts ,,,such that maximum sum of one partition 
should be as minimum as possible.


3. So, here u decide the range of maximum sum possible.

4. If (n=1) then max_sum_possible=sum of all element 
5. if (n=m[length of the array ]) then the max_sum_possible=max_element of the array .
6. So here we do the iteration using for loop and can create one check (function ) , which will check whther
it is possible to divide the array into n parts with the given (max_sum_value).

*/
#include<bits/stdc++.h>
using namespace std;
bool check(int n,int m, int k, vector<int> arr){
    /*
    check function will try to break the one partition with 
    maximum sum of n.....and after iterating the whole array,
    if we were able to make the  k partiiton.(If yes then return true, else return false)

    */
   int sum=0;
   int cnt=0;
   int i=1;
   while(i<=m){
    sum=sum+arr[i];
    if(sum<=n){
        i++;
    }
    else {

        // ✨✨✨✨ U missed this condition , so remember to write it.
        if(arr[i]>n) return false;
        cnt++;
        sum=0;
        i++;
    }
   }

    // this cnt+1 is required
   if(cnt+1<=k) return true;
   else return false;
}
int  solve( int k,vector<int> arr , int n){
    int sum=0;
    int max_el=-1;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        max_el=max(max_el,arr[i]);
    }
    //  cout<<check(29,10,3,arr)<<endl;
    int st=max_el;
    int end=sum;
    bool found=false;
    int ans=-1;
    while(st<=end && found==false){
        // int mid=(st+end)/2;
        // if(check(mid,n,k,arr)==true && check(mid-1,n,k,arr)==false){
        //     ans=mid;
        //     found=true;
        // }
        // else if (check(mid,n,k,arr)==true){
        //     end=mid-1;
        // }
        // else {
        //     st=mid+1;
        // }

        int mid=(st+end)/2;
        // cout<<"st: "<<st<<" end: "<<end<<" mid:"<<mid<<" check?:"<< check(mid-1,n,k,arr)<<" ans:"<<ans<<endl;
        if (mid==max_el && (check(mid+1,n,k,arr)==true && check(mid,n,k,arr)==true )){
            
            ans=mid;
            
            found=true;
        }
       
        if (check(mid,n,k,arr)==false && check(mid+1,n,k,arr)==false ){
            st=mid+1;
           
        }
        else if(check(mid,n,k,arr)==true && check(mid-1,n,k,arr)==false){
            ans=mid;
        
            found=true;
            break;
        }
         else if(check(mid,n,k,arr)==false && check(mid+1,n,k,arr)==true){
            ans=mid+1;
          
            found=true;
            break;
        }
        else if(check(mid,n,k,arr)==true && check(mid-1,n,k,arr)==true){
          
            end=mid-1;
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

    cout<<solve(k,arr1,n)<<endl;
	return 0;
}
	


/*
// input1 :
10
3
5 3 20 16 18 1 10 10 9 8




// output1:
37


// input 2 :
5
4
1 2 3 4 5

// output 2:
5

input3:
2
2
1 2

output3:
1

*/

