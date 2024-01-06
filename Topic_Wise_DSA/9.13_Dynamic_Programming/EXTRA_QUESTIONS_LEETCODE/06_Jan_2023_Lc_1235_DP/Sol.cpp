class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        // order-> {{endtime,startTime},profit}
        vector<pair<pair<int,int>,int>>arr;
        for(int i=0;i<startTime.size();i++){
            arr.push_back({{endTime[i],startTime[i]},profit[i]});
        }

        sort(arr.begin(),arr.end());

        map<int,int>dp;
        dp[0]=0;

        for(auto it : arr){
            int currStartTime=it.first.second;
            int currEndTime=it.first.first;
            int currProfit=it.second;

            // If any job p
            // upper_bound(startTime) finds an iterator pointing to the first element in the dp map whose key is greater than startTime. 


            auto prev_Ind=prev(dp.upper_bound(currStartTime));

            // prev function found the iterator corresponsdint to the upper_bound element 
            //prev is then used to get an iterator pointing to the element with the largest key that is strictly less than startTime

            // it may happen that more than one element present with the upper bound, so prev return the iterator to the largest key.
            int MoreProfit=prev_Ind->second;
            int totalProfit=MoreProfit+currProfit;


            // If the current total profit is greater than the map last profit, then only insert it.
            // dp[i] store the best answer till the index i(here i=end time)
            // So, if we are sorted the arr acoording to the end time, so for next end time, which is then all previous, if its, totalprofit is greater among the last endtime, because AGAR HUM KAM END TIME PAR MORE PROFIT ACHIEVE KAR PAA RAHE HAI , THEN WE WILL CONSIDER THE LESS END TIME.

            // So , basically profit will store  in the map , also in ascending order, maximum profit will be present at end.
            if(totalProfit>dp.rbegin()-> second){
                dp[currEndTime]=totalProfit;
            }
        }

        //   dp.rbegin()->second is used to retrieve the value associated with the largest key in the dp map

        for(auto it : dp){
            cout<<"key:"<<it.first<<" Profit:"<<it.second<<endl;
        }
        return dp.rbegin()->second;
    }
};


/*
Input1
startTime =
[1,2,3,3]
endTime =
[3,4,5,6]
profit =
[50,10,40,70]
Stdout
key:0 Profit:0
key:3 Profit:50
key:5 Profit:90
key:6 Profit:120
Output
120
Expected
120

Input2
startTime =
[1,2,3,4,6]
endTime =
[3,5,10,6,9]
profit =
[20,20,100,70,60]
Stdout
key:0 Profit:0
key:3 Profit:20
key:6 Profit:90
key:9 Profit:150
Output
150
Expected
150


Input3
startTime =
[1,1,1]
endTime =
[2,3,4]
profit =
[5,6,4]
Stdout
key:0 Profit:0
key:2 Profit:5
key:3 Profit:6
Output
6
Expected
6

*/