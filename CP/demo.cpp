/*
Approach:
--> n , k and array is given .
--> find the minimum effort , by choosing any element x from the array. effort= For all i=1 to k sum[(arr[i]-x)]

-> ✨ Now , if we want to find the minimum sum , we need to choose the correct x value.
-> ✨ Best x value , is the median value after sorting the array.
-> ✨ If the array is of even length , then find the effort from both the median value.
-> ✨ If the array is of odd length , then find the effort from the meadian value of the array.


-> ⁉️🤔 Which k number u should select--> Select the k number in sorted order, as they will give the min effort value .
-> Using 1 for loop ...use sliding window of k size and calculate effort and store the minimum effort in min valriable.

-> U can also calculate effort for 1 pair in O(1) operation.

*/


// TC=
// SC=


#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> arr,int n,int max_packet,int rate , int maxtime) {

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********


    //*********
    // 1-- based indexing are used here

   
   
}






/*

input :




output:



*/

