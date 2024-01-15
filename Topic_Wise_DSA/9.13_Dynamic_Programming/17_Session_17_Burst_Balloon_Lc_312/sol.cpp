// TC=O(n3)
// SC=O(n2)
/*
Approach.
1. Calaculate the dp state for len=1 ...means caclaute dp[1][1], dp[2][2],......dp[n][n].
2. Calculate for len=2. and create general formula.
3. dp[i][j]=It tells us the best answer for dp[i][j] when we are burning the elements from i to j.
4. for len=2...we have 2 options whther to burn the first element first , or burn the 2 element first. and we need to takt the maximum coins among them .
5.Lets say K is the variable which is denoting the last element we are burning.
so, dp[i][j]..when last el burnign is k , then dp[i][j]=dp[i-1]*dp[k]*dp[j+1] + if(k-1>=i) then add also dp[i][k-1] and if (k+1<=j) then add also dp[k+1][j]

6. Now if the len of the array u are decided burn is 4, then k will vary from 1 to 4 , so calculate dp[i][j] from 1 to 4 and store the maximum among all of them in dp[i][j] state.

*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //  as i-1 and i+1 is out of boudn we need to cosnider 1 , so we can create new vector element in that way.
        vector<int> arr;
        arr.push_back(1);
        for(auto it : nums) arr.push_back(it);
        arr.push_back(1);
        int n=nums.size();
        vector<vector<int>> dp(n+5,vector<int>(n+5,0));
       
        // now calaute the dp state for 1 length , means dp[1][1], dp[2][2].......dp[n][n]
        

        // Now this new array is just working like 1 based indexing arr.
        int i=1;
        while(i<=n){
            dp[i][i]=arr[i-1]*arr[i]*arr[i+1];
            i++;
        }

        // Lets find the dp state for length 2 and more.
        int len=2;
        while(len<=n){
            int i=1;
            int j=i+len-1;
            while(j<=n){
                // k-> it denotes that we decided to burn the kth element as the last element .
                int k=i;
                dp[i][j]=INT_MIN;
                while(k<=j){
                    int temp=arr[i-1]*arr[k]*arr[j+1];
                    if(k-1>=i){
                        // then cosider dp[i][k-1] state also.
                        temp+=dp[i][k-1];
                    }
                    if(k+1<=j){
                        temp+=dp[k+1][j];
                    }

                    dp[i][j]=max(dp[i][j],temp);
                    k++;
                }

                i++;
                j++;

            }
            len++;
        }

        // final ans is stored in dp[1][n]
        return dp[1][n];

    }
};