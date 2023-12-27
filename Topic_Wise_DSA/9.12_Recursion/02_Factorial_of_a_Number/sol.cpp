
// TC=O(n)
// The time complexity of the sum function is O(n) because, in the worst case, it makes n recursive 
// calls (from n to 0). The solve function simply calls the sum function, so its time complexity is
// also O(n).
// SC=O(n) [ 10 recursion call will made] [ RECURSION STACK SPACE is maximum length of the recursion tree]

#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    // if number is 0, then it's answer will be 0
    if(n==1) return 1;
    else return n*factorial(n-1);
}
int solve(int n){
    return factorial(n);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********

	int n;
    cin>>n;

    cout<<solve(n)<<endl;
	return 0;
}
	


/*
// input1 :
3

// output1:
6

// input 2 :
5

// output 2:
120


input3:
7

output3:
5040

*/

