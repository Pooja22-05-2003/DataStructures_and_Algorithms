// 1. Recursion
// TC=O(2^n*(n*w))  additional(n*w) because at each time u are copying the string to other and passing in the rescursion as res during concatination with  result.
// SC=O(depth*New Copy at each depth) => O(n*(n*w))
class Solution {
public:
    int solve(int ind,vector<string>&arr,string res){
        // base case
        unordered_set<char>s(res.begin(),res.end());
        if(res.size()!=s.size()) return 0;
        
        if(ind>=arr.size()) return res.size();
        // Let's take without checking the condition as when recursion will, it will atumatically stop, of that is not valid.
        int opt1=solve(ind+1,arr,res+arr[ind]);

        // not take
        int opt2=solve(ind+1,arr,res);

        return max(opt1,opt2);

    }
    int maxLength(vector<string>& arr) {
        string res="";
        return solve(0,arr,res);
    }
};