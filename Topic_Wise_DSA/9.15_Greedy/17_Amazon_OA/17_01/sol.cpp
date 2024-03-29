/*


//TC=O(nlogn)
// SC=O(1)


1. Try to put the maximum number of element in one group which satisy the condition.
2. So by sorting we can ensure that the window size which we selected the first and the last element is the max and min ele. if that diff<k, it means all the middle el will also satisfy the condition
3. Maintain the condition and iterate to check the minimum group required.
*/

#include<bits/stdc++.h>
using namespace std;

int  solve(vector<int>arr, int k,int n){
    int minGroup=1;
    sort(arr.begin(),arr.end());
    int i=1;

    int diff=0;
    int prev=1;
    while(i<=n)
    {
        diff=arr[i]-arr[prev];

        if(diff>k)
        {
            
           minGroup++;
        //    cout<<"i:"<<i<<" minGroup:"<<minGroup<<endl;
           prev=i; 
        }
        i++;
    }
    return minGroup;
}  


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int ans=solve(arr,k,n);
    cout<<"ans:"<<ans<<endl;
	return 0;
}
	

/*
input1 :
7
3
1 5 4 6 8 9 2

Output 1:
ans:3





input2 :
7
3
1 2 3 4 5 6 7


Output2:
ans:2


*/


