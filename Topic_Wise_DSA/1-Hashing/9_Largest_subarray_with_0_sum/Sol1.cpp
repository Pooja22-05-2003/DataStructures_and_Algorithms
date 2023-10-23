// Problem Link : https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
/*
Using Hashing
         0, 1, 2, 3,4,5, 6, 7
Arr[]={ 15,-2, 2,-8,1,7,10,23}
Prefix={15,13,15,7,8,15,25,48}
Sum

Unordered_Map store {el->index [First Occurence of that ele]}}

Here 
if found prefixSum[i]==0 then update the maxLen=max(maxLen,i+1)
else if (Map.find(PrefixSum[i])!=Map.end()) maxLen=max(maxLen,(i-Map[PrefixSum[i])])


*/


class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> PrefixSum;
        int maxLen=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0) maxLen=max(maxLen,i+1);
            else {
                if(PrefixSum.find(sum)!=PrefixSum.end()) maxLen=max(maxLen,(i-PrefixSum[sum]));
                else PrefixSum[sum]=i;
            }
        }
        
        return maxLen;
    }
};