// TC=O(N)
// SC=O(N2)


class Solution {
public:
    int minSteps(string s, string t) {
        if (s.size()!=t.size()) return 0;
        unordered_map<char,int> m1;
        unordered_map<char,int>m2;
        int ans=0;
        for(auto it : s){
            m1[it]++;
        }

        for(auto it : t){
            m2[it]++;
        }

        for(auto it : m1){
        char temp=it.first;
        if(m2.find(temp)==m2.end()) ans+=m1[temp];
        else if (m1[temp]>m2[temp]) ans+=(m1[temp]-m2[temp]);
           
        }

        return ans;
    }
};

