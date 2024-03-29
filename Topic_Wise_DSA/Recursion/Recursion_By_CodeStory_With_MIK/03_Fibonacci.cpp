// TC=O(2^n)
// SC=O(n)
/*
Time Complexity (TC):

The time complexity of the Fibonacci function Fibonacci(n) can be expressed using a recurrence relation. Each call to Fibonacci(n) results in two recursive calls, one for Fibonacci(n-1) and one for Fibonacci(n-2), except for the base cases.
The recursion tree for Fibonacci looks like a binary tree, with each level branching into two further levels.
At each level, the number of function calls doubles. Hence, the time complexity can be approximated by O(2^n), where n is the input.
However, due to overlapping subproblems, dynamic programming can be applied to reduce the time complexity to O(n) using memoization or tabulation.
Space Complexity (SC):

The space complexity of the recursive approach is determined by the maximum depth of the recursion tree.
Since at max the depth can go upto O(n), so its space complexity would be O(n)
However, with memoization, the space complexity can be reduced to O(n) as we only need to store the results of subproblems.
*/
#include <bits/stdc++.h>
using namespace std;

int Fibonacci(int n)
{
    // Base Case 
    if(n==0) return 0;
    if(n==1) return 1;
    return Fibonacci(n-1)+Fibonacci(n-2);
}
int solve( int n)
{
   return Fibonacci(n);
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
2

Output 1:
ans:1


input2 :
3

Output 2:
ans:2

Input 3:
4

output3:
ans:3


Input4:
5

Output :
ans:5






*/
