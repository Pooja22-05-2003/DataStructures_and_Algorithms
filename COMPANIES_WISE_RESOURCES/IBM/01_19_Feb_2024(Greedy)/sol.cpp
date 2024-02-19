/*
Approach.
1. It is a greedy problem.
2. Sort the array 
3. Convert the middle element to k , add the number of operation in answer.
4. Convert the left half of the array to less than equal to k.
5. Convert the right half of the array to greater than equal to k.


*/


// TC=O(nlogn)
// SC=O(1)
#include<bits/stdc++.h>
using namespace std;

int  solve(int n,int k,vector<int>arr){
    sort(arr.begin(),arr.end());
    int operation=0;

    int mid=n/2;
    operation+=(abs(k-arr[mid]));

    int i=0;
 
    while(i<n)
    {
        if(arr[i]<arr[mid])
        {
            operation+=(abs(k-arr[i]));
        }
        i++;
    }
   
    i=mid+1;
    while(i<n)
    {
        if(arr[i]<arr[mid])
        {
            operation+=(abs(k-arr[i]));
        }
        i++;
    }
    
   return operation;
  
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

    vector<int>arr(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<solve(n,k,arr)<<endl;

	return 0;
}
	

/*
input1 :
5
2
3 3 6 3 9


Output 1:
3



input2 :


Output2:



*/


