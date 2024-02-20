class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int>s;
        for(auto it : nums) s.insert(it);
        
        int num=-1;
        int i=0;
        for(auto it : s)
        {
          
            if(it!=i) return i;
            
            i++;
        }
        return i;
    }
};