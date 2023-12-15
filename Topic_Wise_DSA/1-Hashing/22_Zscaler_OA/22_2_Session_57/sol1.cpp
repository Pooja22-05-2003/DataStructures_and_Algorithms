/*
Approach - As if the array contai n only positive elements , then maxim sum would be of size k
(Then que changes to find the maximum subarray of size k)

But as here -ve ele are also present 
Then for any index i .....we will check for subarray of size 1,2 till.....k size and fill find the maximum ans for that index.
-> Using prefix sum array for ind=i   subarray_sum [i] from 

=> If k=3 then we will consider only these 3 indexes.
->  i to i=prefix[i]-prefix[i-1]
-> i to i-1=prefix[i]-prefix[i-1-1=(i-2)]
-> i to i-2=prefix[i]-prefix[i-3]

=> 🤔Now here we are subtracting numbers from preix [i] and we want maximum ans(✨So, we should subtract the min value from it)
=> We can maintain this min value (USING HEAP(PRIORITY QUEUE))=> and we should remove the indexes pair(which is not in range of l to r)


-> We will repeat this for all the indexes from index 1 to n .
-> Then find the maximum ans from all the index and return that as answer,
*/


/*



*/

// TC=O(n)
// SC=O(n)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr,int n , int k){
   vector<int> prefix(n+1,0);
   prefix[1]=arr[1];

   for(int i=2;i<=n;i++){
    prefix[i]=prefix[i-1]+arr[i];

   }

    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,0});

    int i=1;
    int maxans=INT_MIN;
   
   while(i<=n){
    //  calculate the left and right range
    
    //  for this , i will check the minimum value from range i to i-k-1
    int l=i-k-1;
    int r=i;
    bool found=false;
     int temp=INT_MAX;
    while(!pq.empty() &&  found==false ){
        pair<int,int> p=pq.top();
        int min_el=p.first;
        int ind=p.second;
       
        // we are only allowed to take the el, which has indexes in the range of l to r
        if(ind>=l && ind<=r){

            temp=min(temp,min_el);


            found =true;
        }
        else {
            pq.pop();
        }

    }
    if(temp==INT_MAX){

    }

    else {
        maxans=max(maxans,arr[i]-temp);
    }
    

    pq.push({prefix[i],i});
    i++;
   }

   return maxans;
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
6
4
-3 4 3 -2 2 5


// output1:
8

// input 2 :
7
6
4 3 -2 9 -4 2 7

// output 2:
9 (but correct output is 15)
*/
