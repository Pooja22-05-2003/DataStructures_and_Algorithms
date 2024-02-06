#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    
    
    ll n; 
    cin>>n;
    
    vector<ll> a;
    for(int i=0; i<n; i++) 
    {
        ll x; 
        cin>>x;
        a.push_back(x);
    }
    
    
    // pow 
    ll pow[32]={0};
    
    pow[0]=1;
    
    for(int i=1; i<32; i++) 
    {
        pow[i]=2*pow[i-1];
    }
    
    
    
    ll sum=0;
    
    //  for each bit pos. 
    for(int i=0; i<32; i++) 
    {
       
       vector<ll> prefix0(n, 0);
       vector<ll> prefix1(n, 0);
       
    //   prefix0[j] :- if i'm considering array elements from 0 --> jth idx then what is the
    //                 no. of subarrays in which ith bit is unset. 
    
    // prefix1[j] :- if i'm considering array elements from 0 --> jth idx then what is the
    //               no. of subarrays in which ith bit is set.
        
        if((a[0] & (1<<i))==0) prefix0[0]=1;
        else
            {
                prefix1[0]=1;
                
            }
        
        for(int j=1; j<n; j++) 
        {
            ll mask=1<<i;
            
            if((a[j]&mask)==0) 
            {
                // this array element is unset at ith bit pos. 
                
                prefix0[j]=1+prefix0[j-1];
                prefix1[j]=prefix1[j-1];
            }
            else
            {
                // swap prefix0 & prefix1 then add 1 in prefix1  
                
                prefix0[j]=prefix1[j-1];
                prefix1[j]=prefix0[j-1]+1;
            }
        }
        
        ll total=0; // total subarrays whose ith bit is set. 
        for(int j=0; j<n; j++) total+=prefix1[j];
        
        sum+=pow[i]*total;
    }
    
    
    cout<<sum<<" ";
    
    
   return 0;
}


/*
Input :
3
1 2 3

Output : 
10


*/