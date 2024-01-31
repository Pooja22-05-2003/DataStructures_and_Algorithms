/*
Brute force approach:
1. Check for all the subarray by using 2 for loop using i and j.
2.Then in each for loop, iterate through i and j and check using bit move(for loop from i=30 to 1),whether using the 
special move, u can make the subarray 0 or not. If yes the increment the ans++.
3. TC=O(n^2*n*30)
4. Finally Return the ans.



Optimized Approach:
1.We can do this using Bit manipulation and Bit Masking .(Represeting the binary number sequence in the form of decimal number. )
2. Conver the whole array into bit. , Now at each array ind i, if the (Bit wise sequence is same for any two index, then it means element inbetween them contain even number of 1 and we can make it to 0).
3. Refer img1 where we converted bitwise count into prefix sum array.(can store in hash array ).
4. Then in img 2, see the even count are replaced with 0 and odd count are replaced with 1.
5. See the code for more clearance.

*/

// TC=O(N*30)
// SC=O(N)
#include <bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>arr)
{
   vector<int>freq_1(40,0);

    // this will store the freq of the same sequence which is present now at ith index occured previosuly.

   unordered_map<int,int>mp;

//   Empty subarray is also possible and it has no element so sequence -> digit conversion is 0.
    mp[0]++;

    int i=1;
    int ans=0;
    while(i<=n)
    {
        int num=arr[i];

        int decimal_conversion_of_sequence=0;

        // j--> row
        for(int j=30;j>=0;j--)
        {
            int g=(num>>j);
            if((g&1)==1)
            {
                freq_1[j]++;
            }

            // col sequence -> is stored in  decimal_conversion_of_sequence
            if(freq_1[j]%2!=0)
            {
                int ith_Bit_decimal=(1<<j);
                decimal_conversion_of_sequence+=ith_Bit_decimal;
            }
        }

        // decimal_conversion_of_sequence-> decimal conversion of current status.

        ans=ans+mp[decimal_conversion_of_sequence];
        mp[decimal_conversion_of_sequence]=mp[decimal_conversion_of_sequence]+1;


        i++;
    }

    return ans;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********

    // Enter the decimal number.
    int n ;
    cin>>n;

    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    cout<<solve(n,arr);
    return 0;
}

/*
// input1 :
4
1 0 3 2


// output1:

2



// input 2 :


// output 2:







*/
