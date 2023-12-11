// Little optimize approach

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int target=n/4;

        unordered_map<int,int> Map;
        for(int i=0;i<n;i++){
            Map[arr[i]]++;
            if(Map[arr[i]]>target) return arr[i];
        }

        return arr[0];
    }
};