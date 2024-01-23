// 1. Backtracking
// TC=O(2^n*w)  In Backtracking from intially we are taking only 1 string(check function in set taking O(n) at each recursion)
// SC=O(depth*New Copy at each depth) => O(n*w) [ w space is for set]
class Solution {
public:
    int solve(int ind,vector<string>&arr,string &res){
        // base case
        unordered_set<char>s(res.begin(),res.end());
        if(res.size()!=s.size()) return 0;
        
        if(ind>=arr.size()) return res.size();
        // Let's take without checking the condition as when recursion will, it will atumatically stop, of that is not valid.
        for(auto it : arr[ind]) res.push_back(it);
        int opt1=solve(ind+1,arr,res);

        // not take
        for(auto it : arr[ind]) res.pop_back();
        int opt2=solve(ind+1,arr,res);

        return max(opt1,opt2);

    }
    int maxLength(vector<string>& arr) {
        string res="";
        return solve(0,arr,res);
    }
};