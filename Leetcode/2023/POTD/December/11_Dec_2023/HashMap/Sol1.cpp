class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        float twenty_five_percent=(n*1)/4;

        unordered_map<int,float>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        for(auto it : mp){
            if(it.second>twenty_five_percent)  
            {
               return it.first;
            }
        }
        return -1;
    }
};