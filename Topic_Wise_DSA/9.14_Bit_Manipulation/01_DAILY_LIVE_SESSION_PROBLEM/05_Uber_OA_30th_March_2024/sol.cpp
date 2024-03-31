// // Sir code:https://ideone.com/fw1xNq

// /*
// Convert all the numbers to binary ; now for each column find the optimal value of y
// // But if in any col, count of 0 and 1 are same ,then pick min valu(go with 0)
// ->Whenever the frequency of both bits in a row are equal in that case; go for 0 as it will minimize y

// */

// // TC :- O(N*log(max(a[i])) = O(N*30)
// // Takes O(1) size because no extra data structure; is declared apart from the variables.

// // TC=O(O(n*30))
// // SC=O(1)

// #include <bits/stdc++.h>
// using namespace std;

// int solve( int n, vector<int>arr)
// {
//     int ans=0;

//     for(int i=0;i<=30;i++)
//     {
//         int count0=0;
//         int count1=0;
//         for(int j=0;j<n;j++)
//         {
//             int el=arr[j];
//             int ith_bit=(el>>i)&1;
//             if(ith_bit==0)count0++;
//             else count1++;

//         }

//         if(count0==count1)
//         {
//             // do the xor with 0
//         //    add nothing
//         }
//         else if(count1>count0)
//         {
//             // do the xor with 0
//             // ass  nothing
//         }
//         else{
//             // do the xor with 1
//             ans+=(2<<i);
//         }
//     }

//     return ans;
// }

// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     //**********
//     int n;
//     cin >> n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     int ans=solve(n,arr);
//     cout<<"ans:"<<ans<<endl;
//     return 0;
// }

// /*
// input1 :
// 4
// 5 6 2 3

// Output 1:
// ans:-16

// input1 :

// Output 1:

// */
