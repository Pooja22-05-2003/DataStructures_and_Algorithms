/*
1. As we need to put the maximum number of items in the bag. 
2. Try to put the smaller size items and then bigger than this and so on.
3. Whenver capacity is exceeded , return the number of items u was ablt to put in the bag.
*/

/*

*/

// TC=O(nlogn)
// SC=O(1)
#include<bits/stdc++.h>
using namespace std;

int  solve(vector <int>arr, int n , int c){
   sort(arr.begin(),arr.end());

   int currCapacity=0;
   int cnt=0;
   int i=1;
//    bool found=false;
   while(i<=n )
   {
    currCapacity+=arr[i];
    
    if(currCapacity>c) break;
    cnt++;
    i++;
   }

   return cnt;
  
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
    int c;
    cin>>c;

    vector<int>arr(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    cout<<solve(arr,n,c);

	return 0;
}
	

/*
input1 :
5 10
8 5 4 3 2


Output 1:
3



input2 :


Output2:



*/


