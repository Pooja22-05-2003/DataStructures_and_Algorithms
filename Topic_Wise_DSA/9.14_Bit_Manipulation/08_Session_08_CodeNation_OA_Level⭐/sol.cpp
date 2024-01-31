// // TC=O(N*31)
// // SC=O(N*50)

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 
ll a[200000+5];
ll ok[200000+5][50];
ll sum[200000+5][50];
ll k[55] ;
ll kk(ll x,ll y){
    
    ll vv = abs(x-y)+1;
    ll rr = 0 ; 
    ll i = 31 ; 
    while(i>=0){
        
        ll gg = abs(sum[y][i]-sum[x-1][i]);
        
        if(gg==vv){
            
            rr = ((rr) | (k[i]));
            
        }
        
        
        i--;
    }
    
    //cout<<"\n";
    //cout<<"\n";
    return rr ; 
    
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********
    ll n;
    cin>>n ; 
    ll i = 1 ; 
    while(i<=n){
        cin>>a[i];
        i++;
    }
    
    k[0] = 1 ; 
    i = 1 ; 
    while(i<=50){
        k[i] = (2*k[i-1]);//poewer...of 2....
        i++;
    }
    
    
    int j = 1 ; 
    while(j<=n) {
        for (int i = 31; i >= 0; i--) 
        { 
            int k = a[j] >> i; 
            if (k & 1) {
                //cout << "1";
                ok[j][i] = 1 ; 
            } 
            else{
                //cout << "0";
                }
            
        } 
    j++;
    }
    
    j = 1 ; 
    while(j<=n) {
        for (int i = 0; i <= 31; i++) 
        { 
            sum[j][i] = sum[j-1][i] + ok[j][i];
            
        } 
    j++;
    }
    
    ll q ; 
    cin>>q ;
    
    i = 1 ; 
    while(i<=q){
        ll l1,r1,l2,r2 ; 
        cin>>l1>>r1;
        cin>>l2>>r2;
        //cout<<l1;cout<<"\n";
        ll v2 = kk(l1,r1);
        ll v5 = kk(l2,r2);
        
        //cout<<v2<<" "<<v5 ; 
        
        ll rr = ((v2)^(v5));
        cout<<rr ;
        i++;
    }
    
    
    
    
    
/*
3
3 1 7 
1
1 1 3 3 

9
8 6 5 9 7 7 9 3 8 
1
3 5 5 5 

*/
    
    
    
    
    
    
    
    
    return 0 ; 
}
/*
// input1 :
3
3 1 7 
1
1 1 3 3 



// output1:
4



// input 2 :
9
8 6 5 9 7 7 9 3 8 
1
3 5 5 5 

// output 2:
6






*/


// #include <bits/stdc++.h>
// using namespace std;


// int solve(int n, vector<int> arr , int l1, int l2, int r1 , int r2)
// {
//     vector<vector<int>>matrix(200000+5,vector<int>(50,0));
//     vector<vector<int>>sum(200000+5,vector<int>(50,0));
//     int j=1;
//     while(j<=n)
//     {
//         int num=arr[j];
//         for(int i=31;i>=0;i--)
//         {
//             int g=(num>>i);
//             if((g&1)==1)
//             {
//                 matrix[j][i]=1;
//             }
//         }
//         j++;
//     }

//     // prefix arr, 
//     j=1;
//     while(j<=n)
//     {
//         for(int i=0;i<=31;i++)
//         {
//             sum[j][i]=sum[j-1][i]+matrix[j][i];
//         }
//         j++;
//     }

//     int len1=abs(r1-l1)+1;
//     int decimal=0;
//     int p=31;
//     while(p>=0)
//     {
//         int cnt_1=abs(sum[r1][p]-sum[l1-1][p]);
//         if(cnt_1==len1) decimal=((decimal)|((1<<p)));
//         p--;
//     }
//     int x=decimal;

//     int len2=abs(r2-l2)+1;
//     decimal=0;
//     p=31;
//     while(p>=0)
//     {
//         int cnt_1=abs(sum[r2][p]-sum[l2-1][p]);
//         if(cnt_1==len1) decimal=((decimal)|((1<<p)));
//         p--;
//     }
//     int y=decimal;
//     return (x^y);
// }

// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     //**********

//     // Enter the decimal number.

//     int n;
//     cin >> n;

//     vector<int> arr(n + 1);
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> arr[i];
//     }

//     int l1,l2,r1,r2;
//     cin>>l1;
//     cin>>l2;
//     cin>>r1;
//     cin>>r2;


//     cout << solve(n, arr,l1,l2,r1,r2);
//     return 0;
// }