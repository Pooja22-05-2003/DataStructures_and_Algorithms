// TC=O(n)
// SC=O(n)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>freq(n+1,0);
        vector<int>freq1(n+1,0);
        for(auto it : trust)
        {
            int personTrusting=it[0];
            int PersonTrusted=it[1];
            freq1[PersonTrusted]++;
            freq[personTrusting]++;
        }
        
        for(int i=1;i<=n;i++)
        {
        
            if(freq[i]==0 && freq1[i]==n-1) return i;
            
        }
        return -1;
    }
};