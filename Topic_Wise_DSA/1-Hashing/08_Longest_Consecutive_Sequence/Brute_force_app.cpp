#include <bits/stdc++.h>
/*
Brute force :
By sorting 
TC=O(nlogn)
SC=O(1)


*/

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr.size()==1 || arr.size()==0) return arr.size();
        int maxLen=INT_MIN;
        for(int i=0;i<arr.size();i++){
            int len=1;
            int el=arr[i];
            bool continuous=true;
            while(continuous){
                if((i+1)<arr.size() && arr[i]+1==arr[i+1])
                {
                i++;
                len++; 
                
                }
                else if(i+1<arr.size() && arr[i+1]==arr[i]) i++;
                else continuous=false;
            }
            maxLen=max(maxLen,len);
        }
        return maxLen==INT_MIN ? 0 : maxLen;


    }
};

/*
maxLen=
len=1
100,4,200,1,3,2
1,2,3,4,100,200
*/