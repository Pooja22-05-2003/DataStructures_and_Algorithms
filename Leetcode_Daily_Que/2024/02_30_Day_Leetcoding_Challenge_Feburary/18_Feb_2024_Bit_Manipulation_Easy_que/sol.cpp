class Solution {
public:
    bool isPowerOfTwo(int n) {
        unordered_map<long long ,bool>mp;
        
        for(int i=0;i<=30;i++)
        {
            // cout<<"i:"<<i<<" pow_of_2:"<<(1<<i)<<endl;
            mp[(1<<i)]=true;
        }
        
        long long  num=abs(n);
        
        if(mp.find(n)!=mp.end()) return true;
        else return false;
    }
};