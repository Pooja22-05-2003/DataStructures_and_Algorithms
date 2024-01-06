// Brute Force - check all the possible substrings and count how many of them are pallindrome, then return the count.
// TC=O(n^2*n) [ n^2 for creating all the substring and n for checking that subtring is pallindrome or not]
// SC=O(1)
class Solution {
public:
    bool check(string s, int i, int j){
        int p=i;
        int q=j;
        while(p<q){
            if(s[p]!=s[q]) return false;
            p++;
            q--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int i=0;
        int cnt=0;
        while(i<n){
            int j=i;
            while(j<n){
                // substring are from i to j.
                if(check(s,i,j)==true) cnt++;
                j++;
            }


            i++;
        }
        
        return cnt ;
    }
};





