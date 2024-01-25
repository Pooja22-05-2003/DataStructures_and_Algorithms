/*
Approach:
Que in 1 Lines:
Given an array , u need to find the min possible summation of all the sequences(x1,x2,x3,x4) of possible lenght.

1. In sorted array only , we can get the minimum possbile difference between any 2 possible numbers.
2. So we need to find the minimum possible sum when we divide the array into x sequence of length =g and y sequence of length g+1.
3. As here we can divide the array into many possbile sequence, so we need to try all the possible ways and need to return the minimum ans possible.
4. So, here we will apply dp.
5. dp[i][j]=> It denote the best minimum answer possbile , when we divide the array into i parts of length g and j parts of length g+1.
6. Finally return dp[x][y].

*/


// TC=O()
// SC=O()




#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll dp[5005][5005] ;
ll diff[500000+5];

ll kk(ll y,ll g){
    
    ll vv = 0 ; 
    vv = abs(diff[g] - diff[y]);
    return vv ; 
    
    
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
    //

    //*********
    ll n ; 
    cin>>n ; 
    ll k;
    cin>>k ; 
    ll b[n+1] = {0};
    ll i = 1 ; 
    while(i<=n){
        cin>>b[i] ; 
        i++;
    }
    
    ll p1 = n/k ;//....g 
    ll p2 = n/k + 1 ; //...g+1...
    ll k2 = 0 ;//count of g..basically x.. 
    ll k5 = 0 ; //count of g+1...basically y..
    i = 1 ; 
    while(i<=k) {
        ll vv = (n-i)/k ; 
        vv++;
        if(vv==p1){
            k2++;
        }
        if(vv==p2){
            k5++;
        }
        i++;
    }
    cout<<k2<<" "<<k5 ;
    cout<<"\n"; 
    
   
    sort(b+1,b+n+1);
    
    i = 2 ; 
    while(i<=n){
        ll gg = abs(b[i]-b[i-1]);
        diff[i] = diff[i-1] + gg ;//diff is p-s[]
        i++;
    }
    
    
    
    
    i = 1 ; 
    while(i<=k2){
        
         ll sum = i*p1 + 0*p2;
        ll g = sum ; 
        ll y = (sum - p1 + 1 );
        
        dp[i][0] = dp[i-1][0] + kk(y,g); //base_case...
        
        i++;
    }
    
    
    i = 1 ; 
    while(i<=k5){
        
         ll sum = 0*p1 + i*p2;
        ll g = sum ; 
        ll y = (sum - p2 + 1);
        
        dp[0][i] = dp[0][i-1] + kk(y,g); //base_case...
        
        i++;
    }
    
    
    
    
    
    
    
    
  
    i = 0 ; 
    while(i<=k2){
     ll j = 0 ; 
     while(j<=k5){
         
         
         ll sum = i*p1 + j*p2 ; 
         
         if(sum!=0){
             ll v5 = 1e18 ; 
             if(j>=1){
             //focus on j part....
             
             ll g = sum ; 
             ll y = (sum - p2 + 1 );
             v5 = dp[i][j-1] + kk(y,g);
             }
             ll v8 = 1e18 ; 
             
             if(i>=1){
                 
                  ll g = sum ; 
             ll y = (sum - p1 + 1 );
             v8 = dp[i-1][j] + kk(y,g);
                 
                 
             }
             
             
             dp[i][j] = min(v5,v8);
             
             
         }
         
         
         
         j++;
     }
     i++;   
    }
        
        
        
        
        
        
        
    
    cout<<dp[k2][k5];
    
    
    /*
    
    15 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 

5
-5 -5 3 3 3 

    
    
    */
    
    
    

    
    return 0 ; 
}
// #include <bits/stdc++.h>
// using namespace std;
// int solve(int n,int b,vector<int>arr)
// {

//     vector<int>diff(500000+5);
//     int x=(n/b);
//     int y=(n/b)+1;
//     int g=0;
//     int g_plus_1=0;

//     vector<vector<int>>dp(g+1,vector<int>(g_plus_1+1,0));
//     int i=1;
//     while(i<=b)
//     {
//         int vv=(n-i)/b;
//         vv++;
//         if(vv==x) g++;
//         if(vv==y) g_plus_1++;
//         i++;
//     }

//     sort(arr.begin(),arr.end());

//     // fill base case of dp
//     i=2;
//     while(i<=n)
//     {
//         int dif=(arr[i]-arr[i-1]); // it will help in creating the prefix_diff
//         diff[i]=diff[i-1]+dif;

//     }


//     i=1;
//     while(i<=g)
//     {
//         int sum=(i*x)+(0*y);
//         int g=sum;
//         int y=(sum-x+1);

//         dp[0][i]=dp[0][i-1]+

//     }
    
// }

// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     //**********
//     //

//     //*********

//     int n;
//     cin>>n;

//     int b;
//     cin>>b;
//     vector<int>arr(n+1);
//     for(int i=1;i<=n;i++){
//         cin>>arr[i];
//     }
//     cout<<solve(n,b,arr);

//     return 0;
// }

/*
// // input1 :
5 
3
3 -5 3 -5 3


// // output1:
1 1
0


// // input1 :
6
3
4 3 4 3 2 5

// // output1:
3 0
3

// */