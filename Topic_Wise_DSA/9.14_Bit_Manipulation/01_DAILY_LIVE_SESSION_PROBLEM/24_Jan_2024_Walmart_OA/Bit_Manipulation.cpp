/*
Approach:
See the tabular explaination of the bits.
*/

// TC=O()
// SC=O()

#include <bits/stdc++.h>

using namespace std;
int solve(int a,int b,int c)
{
/*
  // k<=1e9 => 30 bits are required 
  //Therefore, the maximum decimal number that can be represented using 30 bits is 
1,073,741,823==(10^9)


          a | x    &      b | x            c 
0Row      1               1                1   => No need to x=1, x=0 
1Row      1 | 1           0 | 1            1   => Add to x=1 (2^1Row)
2Row      0 | 1           1 | 1            1   => Add to x=1 (2^2Row)
3Row      0 | 1           0 | 1            1   => Add to x=1 (2^3Row)

Observation : If  (a and b) both are 1 then ans will not increment else ans will get incremenet by (2^row)

          a | x    &      b | x            c 
0Row      1               1                0   => Not possible (return -1)
1Row      1 |             0 |              0   => x = 0 
2Row      0               1                0   => x = 0 
3Row      0               0                0   => x = 0 

Observation : if(a and b) both are 1, then ans=0(Because we can never convert 1 to 0 using OR operation)
else we need to do nothing.

*/  

    int ans=0;
    for(int bit=0;bit<30;bit++)
    {
        int a_bit_val= (a &(1<<bit))==0?0:1;
        int b_bit_val= (b &(1<<bit))==0?0:1;
        int c_bit_val= (c &(1<<bit))==0?0:1;

        if(c_bit_val==1)
        {
            if(a_bit_val==1 && b_bit_val==1)
            {
                ans+=0;
            }
            else 
            {
                ans=ans+(pow(2,bit));
            }
        }

        else if (c_bit_val==0) {
             if(a_bit_val==1 && b_bit_val==1)
            {
                ans=-1;
                break;
            }
            else 
            {
                ans+=0;
            }
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