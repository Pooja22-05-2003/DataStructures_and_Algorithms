class Solution {
public:
    bool check(int st,vector<int>& gas, vector<int>& cost )
    {
        int currGas=gas[st];
        int ReqCost=cost[st];
        int ind=st;
        int n=gas.size();
        while(currGas>=ReqCost && ind<gas.size())
        {
            currGas=currGas-ReqCost;
            // cout<<"ind:"<<ind<<endl;
            ind++;
            if(ind==n)  return true;
            currGas=currGas+gas[ind];
            ReqCost=cost[ind];   
        }
        return false;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size=gas.size();
        int totalgas=0;
        int totalCost=0;
        for(auto it : gas) totalgas+=it;
        for(auto it : cost) totalCost+=it;
        
       
        if(totalCost>totalgas) return -1;
        
        for(int i=0;i<gas.size();i++)
        {
            if(gas[i]>=cost[i])
            {
                if(check(i,gas,cost)) return i;
            }
        }
        return -1;
    }
};