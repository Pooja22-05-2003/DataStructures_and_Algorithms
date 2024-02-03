/*
1. As this is a Problem of partition dp.
2. 2D Dp we will make.
3. dp[i][j]=> It will represent the max score to the question till index 'i', when we can partition the
array into atmost 'j' non empty adjacent subarrays.
4. so, if let say we are at index i and k=3, so we can partition the array into 1 subarray, 2 subarray,3 subarray,
among all the partitions , you need to store the max ans for index i, in dp[i][j].
5. First tr
*/
class Solution {
public:
    double largestSumOfAverages(vector<int>& arr, int k) {
       
        int n=arr.size();
        vector<vector<double>>dp(n+1,vector<double>(k+1,0));

        int i=1; // i=1 means partition =1 is allowed
        double sum=arr[i-1];
        while(i<=n)
        {
            double avg=sum/i;
            dp[i][1]=avg;
            i++;
            if((i-1)<=(n-1))sum+=arr[i-1];          
        }
        cout<<dp[1][1]<<endl;
        if(k==1) return dp[n][1];
        if(k==n) return sum;
        else 
        {
             int partition=2;
             while(partition<=k)
             {
                 i=partition; // because dp[1][1] is already filled.
                 while(i<=n)
                 {
                     int j=i;
                     double Currsum=arr[j-1];
                     double cnt=1;
                     double average=(Currsum)/cnt;
                     while(j>=(partition))
                     {
                        //  cout<<"currsum:"<<Currsum<<" cnt:"<<cnt<<" average:"<<average<< "  dp[j-1][partition-1]:"<<dp[j-1][partition-1]<<endl;
                         dp[i][partition]=max(dp[i][partition],(average+dp[j-1][partition-1]));
                       
                          j--;
                         Currsum+=arr[j-1];
                         cnt++;
                         average=(Currsum)/cnt;
                        //  cout<<"i:"<<i<<" j:"<<j<<" avg:"<<average<<endl;
                        
                     }
                       cout<<"dp[i][partition]:"<<dp[i][partition]<<endl;
                     i++;
                 }

                 partition++;
             }
             return dp[n][k];
        }
    }
};