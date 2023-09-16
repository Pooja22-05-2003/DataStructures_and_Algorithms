/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104

*/
//  TC=O(n*2)
//  SC=O(n*2)+O(n)

//  ⚠️⚠️⚠️ U can't call recursion here from back to front
//  Becasue u need to buy first before selling it , and u need to move from front to back only
class Solution {
public:
    int solve(int ind,vector<int>&prices,int buy,  vector<vector<int>> &dp,int fee){
        //  base case
            
            if(ind==prices.size()) return 0;

            int maxProfit=0;
        //  buy - 2 options [ buy on that day , or not buy on that day and let's wait for another day for the stock to reduce its price]


        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy==1){
            int opt1=-prices[ind]-fee + solve(ind+1,prices,0,dp,fee);
            int opt2= 0+solve(ind+1,prices,1,dp,fee);
            maxProfit=max(opt1,opt2);
        }


        //  sell
        if(buy==0){
            //  not selling on that day
            int option1=0+solve(ind+1,prices,0,dp,fee);
            int option2=prices[ind]+solve(ind+1,prices,1,dp,fee);
             maxProfit=max(option1,option2);
        }
        return dp[ind][buy]=maxProfit;
    }
    int maxProfit(vector<int>& prices,int fee) {
      
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,prices,1,dp,fee);
    }
};

