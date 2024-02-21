// TC=O(10^9)
// SC=O(1)

#include <bits/stdc++.h>

using namespace std;
int solve(int a,int b,int c)
{
/*
    // maximum possible bit of X will be v
    // v=max number of bits possible in all 3 numbers-> max_bit(a,b,c)

    for(i=0;i<=2^v;i++){

       if((a|i) & (b|i) == c)
      {
           ans = c 
           break
      }

}

print(ans.)

*/
    int ans=-1;
    for(int i=0;i<pow(10,9);i++)
    {
        if((a|i) & (b|i)==c)
        {
            ans=c;
            break;
        }
    }

    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
    //

    //*********
   
    int A;
    cin>>A;
    int B;
    cin>>B;
    int C;
    cin>>C;
    
    int ans=solve(A,B,C);
    cout<<ans<<endl;
    
    return 0 ; 
}
/*
// // input1 :
3
2
1


// // output1:
-1

// // input1 :

// // output1:

// */