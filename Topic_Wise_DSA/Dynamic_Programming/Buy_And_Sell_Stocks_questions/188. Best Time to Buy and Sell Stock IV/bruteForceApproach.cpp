/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000


*/
/* TC=O(2^k)[The function solve is called recursively for each day, and for each day, it explores two options (buy or not buy).
Since there are k transactions allowed, the maximum depth of the recursion tree can be up to k levels.
In the worst case, for each day, the code explores 2 options k times (for each level of recursion). Therefore, the time complexity is O(2^k), where k is the maximum number of transactions allowed. This can be quite inefficient for large values of k.]


//  SC=O(k) [ recurisve stack space]

*/

//  ⚠️⚠️⚠️ U can't call recursion here from back to front
//  Becasue u need to buy first before selling it , and u need to move from front to back only
class Solution {
public:
    int solve(int ind,vector<int>&prices,bool buy,int capacity){
        //  base case
            if(capacity==0 || (ind==prices.size())) return 0;
           
            

            int maxProfit=0;
        //  buy - 2 options [ buy on that day , or not buy on that day and let's wait for another day for the stock to reduce its price]
        if(buy==1){
            int opt1=-prices[ind] + solve(ind+1,prices,false,capacity);
            int opt2= 0+solve(ind+1,prices,true,capacity);
            maxProfit=max(opt1,opt2);
        }


        //  sell
        if(buy==0){
            //  not selling on that day
            int option1=0+solve(ind+1,prices,false,capacity);
            int option2=prices[ind]+solve(ind+1,prices,true,capacity-1);
             maxProfit=max(option1,option2);
        }
        return maxProfit;
    }
    int maxProfit(int k,vector<int>& prices) {
      
        int n=prices.size();
        return solve(0,prices,true,k);
    }
};