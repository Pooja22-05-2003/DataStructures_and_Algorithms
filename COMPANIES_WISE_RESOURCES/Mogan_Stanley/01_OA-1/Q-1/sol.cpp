#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>


using namespace std;

int totalLength(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int res=0;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=ans[res][1])
            {
                ans[res][0]=min(ans[res][0],intervals[i][0]);
                ans[res][1]=max(ans[res][1],intervals[i][1]);                
            }
            else
            {
                ans.push_back(intervals[i]);
                res++;
            }
        }
    int total_length = 0;
    for (int i = 0; i < ans.size(); ++i) {
        total_length += ans[i][1] - ans[i][0];
    }

    return total_length;
}

int main() {
    int n,m;
    cin >> n>>m;

    vector<vector<int>> intervals(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    int ans = totalLength(intervals);
    cout << ans << endl;

    return 0;
}