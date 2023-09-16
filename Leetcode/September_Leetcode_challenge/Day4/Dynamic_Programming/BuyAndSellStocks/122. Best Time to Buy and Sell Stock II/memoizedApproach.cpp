/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
*/
//  TC=O(n*2)
//  SC=O(n*2)+O(n)

//  ⚠️⚠️⚠️ U can't call recursion here from back to front
//  Becasue u need to buy first before selling it , and u need to move from front to back only
class Solution {
public:
    int solve(int ind,vector<int>&prices,int buy,  vector<vector<int>> &dp){
        //  base case
            
            if(ind==prices.size()) return 0;

            int maxProfit=0;
        //  buy - 2 options [ buy on that day , or not buy on that day and let's wait for another day for the stock to reduce its price]


        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy==1){
            int opt1=-prices[ind] + solve(ind+1,prices,0,dp);
            int opt2= 0+solve(ind+1,prices,1,dp);
            maxProfit=max(opt1,opt2);
        }


        //  sell
        if(buy==0){
            //  not selling on that day
            int option1=0+solve(ind+1,prices,0,dp);
            int option2=prices[ind]+solve(ind+1,prices,1,dp);
             maxProfit=max(option1,option2);
        }
        return dp[ind][buy]=maxProfit;
    }
    int maxProfit(vector<int>& prices) {
      
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,prices,1,dp);
    }
};