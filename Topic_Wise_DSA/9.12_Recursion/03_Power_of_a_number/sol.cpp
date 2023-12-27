// TC=O(power)
//  SC=O(power)

#include<bits/stdc++.h>
using namespace std;

int power(int n , int pow){
    // if number is 0, then it's answer will be 0
    if(pow==0) return 1;
    else return n*power(n,pow-1);
}
int solve(int n, int pow){
    return power(n , pow);
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

    int pow;
    cin>>pow;
    cout<<solve(n,pow)<<endl;
	return 0;
}
	


/*
// input1 :
5
2

// output1:
25

// input 2 :
2
5

// output 2:
32


input3:


output3:

*/

