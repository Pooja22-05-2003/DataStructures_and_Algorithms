class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int g_ind=0;
        int s_ind=0;
        while(g_ind<g.size() && s_ind<s.size()){
            if(s[s_ind]>=g[g_ind]) {
                // if element at s_ind>= element at g_ind then , that cooking can be given to children at g_ind, so we can move g_ind safely.
                g_ind++;
                }
            s_ind++;
        }

        // only g_ind index we were able to move forward, so that would be our answer.
        return g_ind;
    }
};