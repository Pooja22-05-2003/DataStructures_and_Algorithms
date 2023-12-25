/*
Approach :
Pattern - TTTTTFFFFFFFFF
*/

// TC=O(n)
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;
bool check(int target , vector<int> arr1 , vector<int> arr2 , int n, int budget){
    // to attain this target , we need to make all the elements greater than equal to target
    int cost=0;
    for(int i=1;i<=n;i++){
        if(arr1[i]>=target) continue;
        else {
            if(target % arr1[i]==0){
                cost+=((target/(arr1[i]))-1)*arr2[i];
               
            }
            else {
                cost+=(target/(arr1[i]))*arr2[i];

            }
            
        }
    }
  
    if(cost>budget) return false;
    else return true;
    
}

int solve(vector<int>arr1, vector<int>arr2 , int n , int budget){
    int minn=INT_MAX;
    for(int i=1;i<=n;i++){
        minn=min(arr1[i],minn);
    }
    int maxx=INT_MIN;
 
//    for(int i=minn+1;i<=budget;i++){
//     // i=minn+1 means whether it is possible to make the minimum ele in the array to minn+1 whith the budget which we have.
//     if(check(i,arr1, arr2, n , budget)==true){

//         maxx=max(maxx,i);

//     }
//     else break;
//    }
int st=minn;
int end=budget;
while(st<=budget){
    int mid=(st+end)/2;
    // pattern = TTTTTFFFFFF
    if(check(mid,arr1,arr2,n,budget)==true && check(mid+1,arr1,arr2,n,budget)==false){
        return mid;
    }
    else if(check(mid,arr1,arr2,n,budget)==true){
        st=mid+1;
    }
    else end=mid-1;
}

   return maxx;
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

    int budget;
    cin>>budget;
    vector<int> arr1(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }
    vector<int> arr2(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr2[i];
    }

    cout<<solve(arr1,arr2,n,budget)<<endl;
	return 0;
}
	


/*
// input1 :
3
32
4 2 7
3 5 6

// output1:
10

// input 2 :


// output 2:


input3:


output3:


*/

