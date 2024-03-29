//❌❌Not passing all the test cases.
// Greedy Approach

class Solution {
public:
    int minimumPartition(string s, int k) {
        int cnt=0;
        
        string curr="";
        for(int i=0;i<s.size();i++)
        {
            curr+=s[i];
            long long temp=stoll(curr);
            
            if(temp<=k) 
            {
                // ok
            }
            else
            {
                cnt++;
                curr=s[i];
                if(s[i]>k) return -1;
            }
            
        }
        
        if(curr!="")
        {
           long long temp=stoll(curr);
            if(temp<=k) cnt++;
            else return -1;
        }
        return cnt;
    }
};