/*
using hashing:
TC=O(n)
Sc=O(n)

Take 2 hash array
-> First hash array simply mark all the element of the array as true
-> Iterate throught array , if the element-1 is not present in the array that means we can take that array , and can count the len of consectuive subsequence
-> Now mark the element in the visited array as true , if that element you counted in the subsequence
-> Maintain one maxLen and update it regularly 
-> Finally return MaxLen
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        /*
[100,4,200,1,3,2]
arr= {100->true}, {4-> true} , {200-> true}, {1-> true} , {3-> true} , {2-> true}
visited={}

        */
        unordered_map<int,bool> arr;
        for(auto it : nums){
            arr[it]=true;
        }
        unordered_map<int,bool> visited;
        int maxLen=INT_MIN;
        for(auto it : nums){
            if(arr[it-1]!=true && visited[it]!=true){
                //  we can take that element as the starting of the consecutive array 
                int len=1;
                visited[it]=true;
                while(arr[++it]==true  ){
                    len++;
                    visited[it]=true;
                  
                }
                  maxLen=max(maxLen,len);

            }
        }

        return (maxLen==INT_MIN)? 0 : maxLen;
    }
};