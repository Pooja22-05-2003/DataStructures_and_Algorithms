/*
// TC=O(nlogn)
// SC=O(1)
*/

// We need to compute the Return the minimum time needed to complete all tasks.
// So assign the task with large size, to smaller processsing time, so that it will finish fast.
// So, sort both the array and ProcessSor time ko back array se starting wale task ke saath combine karenge, and four processor ka maximum time niklanege.
// Then us maxx ko final result ke saath compare krke, result mei max time store karenge.

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end());
        int ind=processorTime.size()-1;
        int result=0;
        int maxx=INT_MIN;
        for(int i=0;i<tasks.size();i++)
        {
            maxx=max(maxx,(processorTime[ind]+tasks[i]));
            if(i!=0 && ((i+1)%4)==0)
            {
                
              result=max(result,maxx);
                maxx=INT_MIN;
                ind--;
            }
        }
        return result;
    }
};