// Not Giving correct output ❌❌
class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n=colors.size();
        int j;

        vector<int> dp(n,0);
        // string with 1 char is colorful already , so no cost is required
        dp[0]=0;
        if(colors.size()==1) return dp[0];
         cout<<"i:"<<0<<" dp[i]:"<<dp[0]<<" string:"<<colors<<endl;
        if(colors[1]==colors[0]) {
            dp[1]=min(time[1],time[0]);
         
            colors.erase(1,1);
            j=1;

            }
        else{ 
            dp[1]=0;
            j=2;
            }
        int i=2;
       
  
      cout<<"i:"<<1<<" dp[i]:"<<dp[1]<<" string:"<<colors<<endl;      
        while(i<n){
           cout<<"j:"<<j;
            if(colors[j]==colors[j-1]){

                dp[i]=min((time[i]+dp[i-1]),(time[i-1]+dp[i-2]));
                // colors.erase(st index, len of string to delete)
                colors.erase(j,1);
               
                j--;
                }
            
            else dp[i]=dp[i-1];
            cout<<" i:"<<i<<" dp[i]:"<<dp[i]<<" string:"<<colors<<endl; 
            j++;
            i++;
        }

        return dp[n-1];
    }
};


