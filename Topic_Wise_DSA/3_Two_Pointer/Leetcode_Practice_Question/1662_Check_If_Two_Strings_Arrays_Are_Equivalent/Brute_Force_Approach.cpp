// Time Complexity =O(N*k) 
/*
N= size of the word 
K= size of the maximum length word

Space Complexity =O(N*K)   [ Optimize this space complexity ]
//  Compare function also takes O(N*K)


*/
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string s1="";
        string s2="";
        for(int i=0;i<word1.size();i++){
            s1+=word1[i];
        }
        for(int j=0;j<word2.size();j++){
            s2+=word2[j];
        }

        return s1==s2;
    }
};