// prefix array- will store the number of 0's coming from index 0 to i
//  suffix array - will store the number of 1's coming from index i+1 to n-1


// TC=O(n)
// SC=O(n)

class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        vector<int> prefix(n+1,0);
        vector<int> suffix(n+1,0);
        if(s[0]=='0') prefix[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]=='0') prefix[i]=prefix[i-1]+1;
            else prefix[i]=prefix[i-1];
        }

        for(int i=n-2;i>=0;i--){
            if(s[i+1]=='1') suffix[i]=suffix[i+1]+1;
            else suffix[i]=suffix[i+1];
        }

        int maxLen=0;
        for(int i=0;i<n-1;i++){
            maxLen=max(maxLen,(prefix[i]+suffix[i]));
        }

        return maxLen;
    }
};