// TC=O(N)
// SC=O(N)


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int n,int k) {
    unordered_map<int,int> prefix;
    int sum=0;
    prefix[0]=1;

    int m=1;
    int maxLen=INT_MIN;
    while(m<=n){
        sum+=nums[m];
        
        if(prefix.find(sum-k)!=prefix.end()){
            maxLen=max(maxLen,(m-prefix[sum-k]));
            // cout<<"m:"<<m<<" prefix[sum-k]"<<prefix[sum-k]<<endl;
        }
    prefix[sum]=m;
    m++;
    }

    // fixed size sliding window
      int cnt=0;

      cout<<"maxLen:"<<maxLen<<endl;
    if(maxLen!=INT_MIN){
  
    int i=1;
    int j=1;
    int k1=maxLen;
    int summ=0;
    while(j<=n){
        summ+=nums[j];
        if(j-i+1<k1) j++;
        else if(j-i+1==k1){
            // cout<<"sum:"<<summ<<" k:"<<k<<endl;
            if(summ==k) cnt++;
            summ-=nums[i];
            i++;
            j++;
        }
      }
    }

    return cnt;

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********


    //*********
    // 1-- based indexing are used here

    int n;
    cin>>n;

    int k;
    cin>>k;
   
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    cout<<solve(arr,n,k);
}






/*

input :
8
15
10 5 2 7 1 9 8 7


output:
1


*/



