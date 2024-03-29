
// Greedy Approach

// TC=O(n)
// SC=O(1)

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
                if((s[i]-'0')>k) return -1;
            }
            
        }
        
        if(curr!="")
        {
           long long temp=stoll(curr);

            if(temp<=k) cnt++;
            else return -1; // it u will not put this , then also it will pass all the test cases.(This condition will never appear)
        }
        return cnt;
    }
};