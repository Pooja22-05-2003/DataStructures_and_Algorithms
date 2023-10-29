//  TC=O(N)
//  SC=O(N)

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>FrequencyArr;
        vector<int> ans(A.size(),0);
        int count=0;
        for(int i=0;i<A.size();i++){
            FrequencyArr[A[i]]++;
            FrequencyArr[B[i]]++;

            // don't forget to add the first if condition , because for same number without this condition , it will add ans 2 times.
            if(A[i]!=B[i])if(FrequencyArr[A[i]]==2)count++;
            if (FrequencyArr[B[i]]==2) count++;
            ans[i]=count;
        }

        return ans;
    }
};




