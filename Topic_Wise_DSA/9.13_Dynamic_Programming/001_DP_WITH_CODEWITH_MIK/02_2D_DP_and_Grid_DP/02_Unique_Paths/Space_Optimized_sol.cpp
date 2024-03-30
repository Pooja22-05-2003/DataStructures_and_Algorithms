// Tabulation Space Optimization Sol
// TC=O(n)
// SC=O(n)


/*
If u will see the requirement of curr dp[i][j] is the prev col and prev row onnly, 
-> So, we need to maintain only the prev whole row and the curr col value
*/
class Solution {
public:

    int uniquePaths(int m, int n) {
        
      
        vector<int>prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0){
                    temp[j]=1;
                    continue; // must intialize this condition inside the for loop only, else it will give wrong ans
                }
                int up=0;
                int left=0;
                
                if(i-1 >=0) up=prev[j];
                if(j-1>=0)  left=temp[j-1];
                
                temp[j]=(up+left);
               
                
            }
             prev=temp;
        }
        
        return prev[n-1];
    }
};