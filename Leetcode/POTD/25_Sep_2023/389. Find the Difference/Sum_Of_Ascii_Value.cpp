//  Sum of ASCII Values
//  time Complexity=O(2*n)
//  Space Complexity=O(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum=0;
        
        for(int it:t) sum+=it;
        for(int it:s) sum-=it;
        return char(sum);
    }
};