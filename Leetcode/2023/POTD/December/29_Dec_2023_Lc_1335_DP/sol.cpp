/*
Problem in 1 line : Given an array A and d=number of days.Divide the whole array in d subarray. And find the maximum element in each subarray and Do the sum of those maximum element , that would be your totol difficulty and return that as your final answer.
// 🧠 2D DP or 3D DP
// NOt MINE SOLUTION

Intuition
It's obvious DP because the answer of today solely depend on the answer of yesterday.

Approach
Suppose that we need to finish i tasks by day j and we use dp[i][j] to indicate the difficulty of this schedule. All we need to do is to decide what to do on day j. We don't need to care how to allocate jobs before jth day, but how many tasks to do on jth day.
Enumerate k, which indicates we finish [k,i]tasks on day j.

The better cost of dp[i][j] is the minimum value of dp[k][j - 1] + max_difficulty_of_jobs_by_index(k, i)

Complexity
Time complexity: O(n2d)O(n^2 d)O(n 
2
 d)
Space complexity: O(nd)O(nd)O(nd), or O(n)O(n)O(n) if use a rolling array saving only today and yesterday's answers.
*/
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        // Create a dynamic 2D array using vectors
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, d); j++) {
                int curDiff = 0;

                for (int k = i; k >= 1; k--) {
                    curDiff = max(curDiff, jobDifficulty[k - 1]);
                    // Check for overflow before addition
                    if (dp[k - 1][j - 1] != INT_MAX && curDiff != INT_MAX - dp[k - 1][j - 1]) {
                        dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + curDiff);
                    }
                }
            }
        }

        return dp[n][d] == INT_MAX ? -1 : dp[n][d];
    }
};







