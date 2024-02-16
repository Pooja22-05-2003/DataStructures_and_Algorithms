// TC=O(nlogn)+O(n)
// SC=O(2n) // first is for map, second is for a
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>freq;
        for(auto it : arr) freq[it]++;
        
        vector<int>a;
    
        for(auto it : freq) a.push_back(it.second);
        sort(a.begin(),a.end());
        
        int cnt=0;
        for(int i=0;i<a.size();i++)
        {
            cnt+=a[i];
            if (cnt>k)
            {
                return a.size()-i;
            }
        }
        
        return 0;
       
    }
};