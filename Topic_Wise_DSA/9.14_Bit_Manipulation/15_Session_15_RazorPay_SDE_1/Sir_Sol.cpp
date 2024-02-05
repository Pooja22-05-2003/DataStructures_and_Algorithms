https://ideone.com/PUPJvE

#include <bits/stdc++.h>


#define ll long long

using namespace std;

int main() {
    
    ll n; cin>>n;
    
    vector<ll> a;
    
    for(int i=0; i<n; i++) 
    {
        ll x; cin>>x; 
        
        a.push_back(x);
    }
    
    
    
    
     // since, pow(2, i) is logn operation so we are precomputing the pow(2, i) for each bit.
    int pow[32]={0};
    pow[0]=1;
    
    for(int i=1; i<32; i++) 
    {
        pow[i]=2*pow[i-1];
    }
    
    
    ll sum=0;
    
    // for each bit
    for(int i=0; i<=31; i++) 
    {
        
        // no. of and values which are set for ith bit
        vector<ll> temp;  // store the idx if for the ith bit a[j] is set
        
        for(int j=0; j<n; j++) 
        {
            if((a[j] & (1<<i))!=0) 
            {
                temp.push_back(j);
            }
        }
        
        
        if(temp.size()==0) continue;
        
        
        // total subarrays in which ith bit will be set.
        ll total=0;
        
        
        if(temp.size()==1)  // only one array element whose ith bit is set
        {
            total++;
        }
        else 
        { // // since, in temp idxes are present so they are in sorted order

// to fig. out subarray for the contiguous idx.
          int i1=0, j1=1;
          
           total=1; // if we only consider i1 idx element then it will give us 1 subarray & then 
                    // for the rest we are first checking if idx are contiguous or not. 
          
          while(j1<temp.size()) 
          {
            //   cout<<j1-i1+1<<" ";
              
              if(temp[j1]-1==temp[j1-1]) // contiguous idx.
              {
                  total+=j1-i1+1;  // j1-i1+1 new subarrays will get included in total
                  
                  j1++;
              }
              else // not contiguous
              {
                  i1=j1;
                  j1++;
                  
                  total++;  // consider this case --> 0 1 2 3 5 6 7
              }
          }
          
          // consider this case --> 0 1 2 3 5 6 7   & dry run the code. 
        }
        
        sum+=(pow[i]*total);
    }
    
    
    cout<<sum;
    

   return 0;
} 
