class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());

        int arrowNeeded=1;
        int minn=INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            minn=min(minn,points[i][1]);

            if(minn<points[i+1][0])
            {
                // means not overlapping , we need one arrow
                arrowNeeded++;
                minn=points[i+1][1];
            }
        }

        return arrowNeeded;
    }
};