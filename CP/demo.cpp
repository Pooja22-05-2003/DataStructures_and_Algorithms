// TC=O(N)
// SC=O(N)
#include<bits/stdc++.h>
using namespace std;

void solve(int n ){
    for(int i=10;i>=0;i--)
    {
        int k=(n>>i);

        if((k&1)==1)
        {
            cout<<"1";
        }
        else 
        {
            cout<<"0";
        }
    }
    
}  

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
     
    // Enter the decimal number.
    int n;
    cin>>n;
    solve(n);
	return 0;
}
	


/*
// input1 :
5


// output1:
00000000101




// input 2 :
4

// output 2:
00000000100


input :
24

output :
00000011000

input :
25

output :
00000011001




*/

