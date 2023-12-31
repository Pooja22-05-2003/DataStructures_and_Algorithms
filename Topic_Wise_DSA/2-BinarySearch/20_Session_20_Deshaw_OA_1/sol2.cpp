// // Optimized approach: https://ideone.com/SvJnz04
// /*
// Approach:
// 1.Let's say we can make y groups.
// 2. So, we need to maximize the value of y.
// 3. So, we need to make y group and each group must be of size , then (** so (k*y) >= sum of all the elements),
// then only , we can make these groups.
// 4. so ,we check for y=1 to sum of the ele
// lets say y=1 is possible.....y=2 is possible.....y=3 is possible ....but y=4 is not possible....it 
// 5. It ensures that y=6,7.....will also will never be possible.
// 6.So, it follow the patter of YYYYYYYNNNNNNN
// 7. If we will do linear search from y=1 to (sum of all el) 
// Tc=O(sum*n) [For each iteartion check will take O(n) time]
// Sc=O(1)

// 8. But by using the binary search , we can reduce the space from O(sum*n)-----> O(log(sum*n))
// */


// //Tc=O(log(sum*n))
// // sc=O(1)

// /*
// Check function working.

// check function is checking whther it is possible to make y groups for particular k value.
// -> Here y=maximum number of portfolio
// -> This is only possible when y*k elements are atleast present in the array.
// -> So for every index ....if(number of el is greater than y..than we can pick those elements and move forward).
// -> But if less element are present at index i than required, then we pick those elements and fill our reaming requirement from next index.
// -> After itearting all index, if we were able to fill the requirement which is target(we will return true) else false.
// */
#include<bits/stdc++.h>
using namespace std;
bool check( int y, int k,vector<int>arr,int n){
    int target=y*k;
    int total=0;
    
    int i=1;
    while(i<=n){
        if(arr[i]>=y){
         
            total+=y;
            arr[i]=arr[i]-y;
            i++;
        }
        else {
            total+=arr[i];
            arr[i]=0;
            i++;
        }
    }

    return (total>=target);
}
int solve(vector<int> arr,int n , int k){
    int st=1;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=arr[i];
    }
    int end=INT_MAX-1; // for safer side, initialize it with sum=sum+5 or more(maximum time initlaize it with INT_MAX)
    int ans=0;
    int y=0;
    while(st<=end && y==0){
        // if(check(st,k,arr,n)==false){
        //     ans=st-1;
        //     break;
        // }
        // else {
        //     st++;
        // }

        int  mid=(st+end)/2;
        if(check(mid,k,arr,n)==true && check(mid+1,k,arr,n)==false){
            ans=mid;
            y=1;

        }
        else if (check(mid,k,arr,n)==true){
            st=mid;
        }
        else {
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

    cout<<solve(arr1,n,k)<<endl;
	return 0;
}
	


/*
// input1 :
3
2
3 3 3


// output1:
4


// input 2 :

// output 2:



*/
