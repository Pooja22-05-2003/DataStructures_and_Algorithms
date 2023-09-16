/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000

*/

//  TC=O(2^n)
//  SC=O(n)

//  ⚠️⚠️⚠️ U can't call recursion here from back to front
//  Becasue u need to buy first before selling it , and u need to move from front to back only
class Solution {
public:
    int solve(int ind,vector<int>&prices,bool buy){
        //  base case
            
            if(ind>=prices.size()) return 0;

            int maxProfit=0;
        //  buy - 2 options [ buy on that day , or not buy on that day and let's wait for another day for the stock to reduce its price]
        if(buy){
            int opt1=-prices[ind] + solve(ind+1,prices,false);
            int opt2= 0+solve(ind+1,prices,true);
            maxProfit=max(opt1,opt2);
        }


        //  sell
        if(!buy){
            //  not selling on that day
            int option1=0+solve(ind+1,prices,false);
            int option2=prices[ind]+solve(ind+2,prices,true);
             maxProfit=max(option1,option2);
        }
        return maxProfit;
    }
    int maxProfit(vector<int>& prices) {
      
        int n=prices.size();
        return solve(0,prices,true);
    }
};