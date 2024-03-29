// TC=O(n)
// SC=O(n)
/*

The time complexity (TC) of the provided code is O(n), where n is the input integer for which the factorial is calculated. 
This is because the factorial function is called recursively, decrementing the value of n by 1 each time until it reaches 1, resulting 
in a linear time complexity.

The space complexity (SC) of the provided code is also O(n). This is because the recursive calls to the factorial function
 generate a call stack, which grows linearly with the size of the input integer n. Each recursive call consumes space on the stack
  until the base case is reached. Therefore, the space required is proportional to the input integer n.
*/
#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    // Base Case 
    if(n<=1) return 1;
    return n*factorial(n-1);
}
int solve( int n)
{
   return factorial(n);
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
