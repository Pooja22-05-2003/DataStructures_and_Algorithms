// TC=O(60)
// SC=O(1)
#include<bits/stdc++.h>
using namespace std;

int solve(int y, int k ){
    int z=0;

    for(int i=60;i>=0;i--)
    {
        int y_ith_bit;
        
        int g=(y>>i);
        // cout<<"g:"<<g<<endl;
        if((g&1)==1)
        {
            // if the ith bit is set , then its and with 1==1
            y_ith_bit=1;
        }
        else 
        {
            y_ith_bit=0;
        }

        int k_ith_bit;
        
        int gg=(k>>i);
        // cout<<"k:"<<gg<<endl;
        if((gg&1)==1)
        {
            // if the ith bit is set , then its and with 1==1
            k_ith_bit=1;
        }
        else 
        {
            k_ith_bit=0;
        }


        // IF both the bit is same then add nothing.
        // if they are different .
        // If yth bit 1 then conversion of 1-->0 is not using possible OR.
        // else add(In bit for additon u can do OR) the ans (1<<i)

        if(y_ith_bit==k_ith_bit)
        {
            // do nothing
        }
        else 

        {
            if(y_ith_bit==1 && k_ith_bit==0) return -1;

            // In bitWise addition happen with OR and not with"+" sign
            else z=z|(1<<i);
        }


    }
    
    return z;
}  

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
     
    // Enter the decimal number.
    int y;
    cin>>y;

    int k;
    cin>>k;
    int ans=solve(y,k);
    cout<<ans<<endl;
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






*/

