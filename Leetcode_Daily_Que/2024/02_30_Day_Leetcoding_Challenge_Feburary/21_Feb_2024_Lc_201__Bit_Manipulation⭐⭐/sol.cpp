Q-1 [Potd-21st Feb,2024] 
Lc-201 Bitwise AND of Numbers Range.
Problem Link :https://leetcode.com/problems/bitwise-and-of-numbers-range/

Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
 
Example 1:
Input: left = 5, right = 7
Output: 4

Example 2:
Input: left = 0, right = 0
Output: 0

Example 3:
Input: left = 1, right = 2147483647
Output: 0

 
Constraints:
0 <= left <= right <= 231 - 1


Approach :
1./*

Brute Force Approach : 

// TC=O(N*30) (N can go upto 10^9)
// SC=O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        for(int i=0;i<=32;i++)
        {
            int temp_AND=1;
            for(long long int num=left;num<=right;num++)
            {
                int ith_bit=(num>>i) & 1;
                temp_AND=temp_AND & ith_bit;
                
            }
            if(temp_AND) ans=ans+(1<<i);
        }
        return ans;
    }
};


*/


Time and Space Complexity :

// TC=O(n*31)
// SC=O(1)


OPTIMIZED SOLUTION : 

// TC=O(32) 
// SC=O(1)

/*
1. AND of (n)&(n-1) -> off the last set bit of n.
2. This loop will not run 1e9, but right will jump drastically.
3. Do the dry run , when left=8 and right=14.


*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
       while(right>left)
       {
           right=right & (right-1);
       }
        return right;
    }
    
};


Solution Link :
https://github.com/Pooja22-05-2003/DataStructures_and_Algorithms/tree/main/Topic_Wise_DSA/9.14_Bit_Manipulation/02_Session_02_Leetcode_Contest_378_Q-1_Bitwise_OR_Trailing_zer

