/*
1. Brute Force :
=> TC=O(N2)
=> SC=O(1)
-> Take one char at a time and iterate through the remaining array , if that element is not present in the remaining array then return that element.

2. Using Hashing 
=> TC=O(N)
=> SC=O(N)
-> In one iteration store the index of that element that occur only once
-> In second iteration find the smallest index.

*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                //  means that element occur previously
                mp[s[i]]=INT_MAX;
                continue;
            }
            else {
                mp[s[i]]=i;
            }
        }


        // find the smallest index element
        int min_index=INT_MAX;
        for(auto it : mp){
            min_index=min(min_index,it.second);
        }

        if (min_index==INT_MAX) return -1;
        else return min_index;
    }
};