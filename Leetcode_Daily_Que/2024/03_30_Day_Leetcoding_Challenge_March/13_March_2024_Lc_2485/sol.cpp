class Solution {
public:
    int pivotInteger(int n) {
        vector<int> prefix(n+1,0);
        vector<int> suffix(n+1,0);

        int sum1=0;
        int sum2=0;
        for(int i=1;i<=n;i++)
        {
            sum1+=i;
            prefix[i]=sum1;
        }
        for(int i=n;i>=1;i--)
        {
            sum2+=i;
            suffix[i]=sum2;
            if(suffix[i]==prefix[i]) return i;
        }

        return -1;
        
    }
};