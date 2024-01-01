/*
Problem in 1 Line :
Given 2 arrays, 1st array us cityA and 2nd is cityB, U need to earn maximum profit. U can pick ele from A or B , from wherever u want.But If u are picking element from
array A and now want to pick from B Then u need to move from arr A to arr B , and here no profit will be earned. So tell the path and earn the maximum profit.

Approach.
-> It,s a Dp Problem , As at the curr index our previous answer will matter.
-> Also, If u are at i index , u need to know whether u picked the previous element from arr A or arrB, So, 1 Dp will not able to work here, 2 Dp are required,
DPa and DPb.
-> So , try to find DPa[1],DPb[1]...., DPa[2],DPb[2]....., Try to formulate the general formula.
-> Then using general formula iterate it....till index n .
-> Return the max(DPa[n],DPb[n])- maximum earning would be our answer.
*/


// TC=O(n) 
// SC=O(2*n)=O(n)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr1,vector<int> arr2, int n){

    vector<int> DPa(n+1,0);
    vector<int> DPb(n+1,0);

    DPa[1]=arr1[1];
    DPb[1]=arr2[1];

    // If taking the current element from arr1 at i ind , then adding the previous best ans from DPa at i-1 index....or taking the curr ele but the previous step is travelling and considering the best ans from DPb[i-2]
    if(n>=2){
    DPa[2]=max(arr1[2]+DPa[2-1] , arr1[2]+DPb[2-2]);
    DPb[2]=max(arr2[2]+DPb[2-1], arr2[2]+DPa[2-2]);

    for(int i=3;i<=n;i++){
    DPa[i]=max(arr1[i]+DPa[i-1] , arr1[i]+DPb[i-2]);
    DPb[i]=max(arr2[i]+DPb[i-1], arr2[i]+DPa[i-2]);       
    }
  }

  cout<<"DPa[n]:"<<DPa[n]<<" DPb[n]:"<<DPb[n]<<endl;
  return max(DPa[n],DPb[n]);
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


    vector<int> arr1(n+1);
    vector<int> arr2(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }

    for(int i=1;i<=n;i++){
        cin>>arr2[i];
    }
    cout<<solve(arr1,arr2,n)<<endl;
	return 0;
}
	


/*
// input1 :
5
25 10 15 10 70 
5 5 50 5 30 


// output1:
DPa[n]:145 DPb[n]:110
145





*/