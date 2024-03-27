//TC=O(N)
// SC=O(1)

class Solution {
public:
  
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalgas=0;
        int totalCost=0;
        for(auto it : gas) totalgas+=it;
        for(auto it : cost) totalCost+=it;
        
       
        if(totalCost>totalgas) return -1;
        
        
        // It is guaranteed now that we can form cycle and reach to the same point
        // 
        int total  = 0;
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            
            total += gas[i] - cost[i];
            // Here i was not able to get the logic, how this is sure that this will reach back to start position and not forms cyle.
            if(total < 0) {
                total = 0;
                result = i+1;
            }
            
        }
        return result;
    }
};