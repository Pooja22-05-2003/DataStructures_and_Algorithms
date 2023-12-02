// Prob Link : https://leetcode.com/problems/find-common-characters/


/*

-> TC=O(n)*O(word.lenght()) [ word.lenght = maximum in worst case will go up to 100]
-> TC=O(n)
-> SC=O(2*26)==O(1)

-> Take 2 hash array 
-> One Unordered map , will maintain the count of the minimum number of  occurence in all the character
-> Initialize the first map with some large number.
-> The Second Map , will maintain the count of all the character of individual word
-> After one word , update the first map , so that it will always maintain the minimum count.
-> after all iterationg make one ans vector string and in the first map , store all the character having that many number of times

*/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> MinFrequenceMap;

        //  initilaize all the characters with some large value 

        // ------> O(26)
        for(char ch='a';ch<='z';ch++){
            MinFrequenceMap[ch]=1000;
        }

        // ------>O(n)
        for(auto it : words){
            string curr=it;
            unordered_map<char,int> frequency;
            // ----->O(Word.length)
            for(int i=0;i<curr.size();i++){
                frequency[curr[i]]++;
            }

            // ------> O(26)
            for(char ch='a';ch<='z';ch++){
            MinFrequenceMap[ch]=min(MinFrequenceMap[ch],frequency[ch]);
        }

        }


        // ----> O(26)*O(word.length)
        vector<string> ans;

        for(auto it : MinFrequenceMap){

            while(it.second>0){
                ans.push_back(string(1,it.first));
                MinFrequenceMap[it.second]--;
                it.second--;
            }
        }

        return ans;
    }
};



