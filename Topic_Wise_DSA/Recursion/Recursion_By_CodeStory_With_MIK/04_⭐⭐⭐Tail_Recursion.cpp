/*
What is Tail Recursion??
1. Recursion jiska last call recursion ho, uske baad koi operation na ho rha ho.
2. Tail recursion mei , memory mei stack space nahi banta. and Space bhot optimized hota hai.

*/

// Tail Recursion code of factorial-> SC=O(1)

// TC=O(n)
// SC=O(1)

#include <bits/stdc++.h>
using namespace std;

int factorial(int n, int res)
{
    // Base Case 
    if(n<=1) return res;
    return factorial(n-1,n*res); // is call ke baad koi operation aur nhi ho rha. that's why it is a tail recursion .
}
int solve( int n)
{
    int res=1;
   return factorial(n,res);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********
    int n;
    cin >> n;
    int ans=solve(n);
    cout<<"ans:"<<ans<<endl;
    return 0;
}

/*
input1 :
5

Output 1:
ans:120


input1 :
3

Output 1:
ans:6





*/
