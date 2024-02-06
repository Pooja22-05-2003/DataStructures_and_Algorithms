/*

Common things we are doing in these kinds of problems are:- 

Visualize → no. in terms of binary.
For each bit pos. We are finding total_cnt & saying in total_cnt ith bit is set. Hence, we are doing 
sum+= pow(2, i) * total_cnt



General approach of this type of problem:
Total triplets = number of ways to select 3 elements from 
cnt1 + number of ways to select 1 element from cnt1 & 2
elements from cnt0; 

Total = n1C3 + n1C1 * n2C2 

Sum += pow(2, i) * Total 

*/


#include <bits/stdc++.h>

using namespace std;

#define ll long long


// Atlassian OA


// finding factorial easily.  --> T(N) = O(R)
ll ncr(ll N, ll R) 
{
    if(N<R) return 0;  // how we can select R items from N if N < R 
    
    ll res=1; 
    
    for(int i=0; i<R; i++) 
    {
        res = res*(N-i);
        
        res = res / (i+1);
    }
    
    return res; 
}


int main() {
    
    ll n; cin>>n;
    vector<int> a(n); 
    for(int i=0; i<n; i++) cin>>a[i];
   
  
//   precomputing to find the pow in O(1) time rather than O(logn) time.  
   ll pow[32] = {0};
   
   pow[0]=1;
   for(int i=1; i<32; i++) 
   {
       pow[i] = 2*pow[i-1]; 
   }
   
    
    ll sum=0; 
    
    // for each bit
    for(int i=0; i<32; i++) 
    {
        
        int cnt0=0,cnt1=0;  
        
        // cnt0 --> no. of a[j] whose ith bit is not set
        
         // cnt1 --> no. of a[j] whose ith bit is set
         
         
         for(int j=0; j<n; j++) 
         {
             int mask=1<<i;
             if((a[j]&mask)!=0) cnt1++;
             else cnt0++;
         }
         
         ll total=0;  // total triplets in which it bit is set. 
         
        //  no. of ways to select 3 set bit from total cnt  --> (cnt1)C3
        
        // no. of ways to select 1 set bit from cnt1 & 2 unset bit from cnt0 
        
    
          total+= ncr(cnt1, 3);   // 1) T(N) to call ncr() --> O(3)
        
        total+= cnt1 * ncr(cnt0, 2);  // 2) T(N) to call ncr() --> O(2)
        
        // cout<<total<<" ";
        
        sum+=pow[i]*total;
    }
    // T(N) = O(32*N*3*2) = O(N)
    
    
    
    cout<<sum<<" ";
    
  return 0;
}

/*
Input :
5
1 2 3 4 5

Output :
40
*/