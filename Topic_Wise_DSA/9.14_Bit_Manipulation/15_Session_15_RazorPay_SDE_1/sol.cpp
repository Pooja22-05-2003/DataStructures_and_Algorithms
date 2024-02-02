/*
Problem statement in 1 line:
Given a array of size n, then find the AND of all the subarray and sum them up and return that final sum.


Approach:
1. In any subarray at ith bit, if the any number of the subarray at the ith bit is unset, then all the subarray which contain that number, it will unset the final sum at the ith bit.
2. At every bit from 0 to 30, store the set or unset value of all the numbers in some vecctor temp.
3. Now all the contiguous one will add at ith bit sum like for number 3,4,2 these are the continguos number in the array and all have 0th bit as set(1), then subarray with length =3=>(n*(n+1)/2)=> (3*(3+1)/2)=>6, it will contirubte 6 times at 2^i bit. (sum+=(6*(2^i))).
4. If the continous number don't have continuous bit at the ith bit, then it only contribute single element subarrays.
5. Do this from 0 to 30 and for every bit, do iterate for each element array.
6. Add it in the final sum.
7. Return sum.


*/
// TC=O(n*30)
// SC=O(n) // temp space
#include <bits/stdc++.h>
using namespace std;


int solve(int n, vector<int>arr)
{
    vector<int>pow(31,0);
   int sum=0;
    pow[0]=1;
    for(int i=1;i<=30;i++){
        pow[i]=(2*(pow[i-1]));
       
    }

    for(int i=0;i<=30;i++)
    {
        vector<int>temp; // this will store the indexes of all the set elements
        int total=0;
        for(int j=1;j<=n;j++)
        {
            int el=arr[j];
            int g=(el>>i);

            if((g&1==1))
            {
                temp.push_back(j); // stored that index.
            }
        }

        

        if(temp.size()==0) 
        {
            continue; // it means every element is unset at the ith position
           
        }
        if(temp.size()==1) {
            total++;
        }
        else 
        {
            int k=0;
            int i=0;
            total=0; // 1 because of empty subarray
            while(k<temp.size())
            {
                if((temp[k]-1)==temp[k-1])
                {
                    total+=(k-i+1); // 3,4 => subaara={4},{4,3}
                    
                    k++;
                    
                }
                else 
                {
                    i=k;
                    k++;
                    
                    total++;

                }
            }
             
        }
       
        sum+=(total*pow[i]);
        
    }
   
    return sum;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********

    // Enter the decimal number.

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }


    cout << solve(n,arr);
    return 0;
}

/*
// input1 :
3
1 2 3


// output1:
8


// input 2 :


// output 2:







*/
