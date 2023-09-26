//  Time Complexity =O(N)
//  Space Complexity =O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=INT_MIN;
        for(int i=0;i<prices.size();i++){
            minPrice=min(minPrice,prices[i]);
            int diff=prices[i]-minPrice;
            maxProfit=max(maxProfit,diff);
        }
        if(maxProfit>0) return maxProfit;
        else return 0;
    }
};