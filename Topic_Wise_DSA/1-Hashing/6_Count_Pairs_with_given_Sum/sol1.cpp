/*
TC=O(N)
SC=O(N)
Approach 1:
Using Hashmap
-> Iterate through array , lets say a+b=k
-> take current ele as a and b=k-a, now add the frequence of map[b] in ans
-> Finally return ans

*/
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            int a=arr[i];
            int b=k-a;
            ans+=mp[b];
            mp[a]++;
        }
        return ans;
    }
};