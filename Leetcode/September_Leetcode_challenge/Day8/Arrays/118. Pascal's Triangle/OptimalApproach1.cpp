//  ✨✨✨✨
//  Time Complexity =O(n2)
//  Space complexity =O(n*n)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>> ans;
        ans.push_back({1});

        //  if size of the numRows is smaller then 2 then simply return the ans here only.
        if(n<2) return ans;
        else {
            //  second row will also contain 2 elements
            ans.push_back({1,1});

            for(int i=0;i<n-2;i++){
               
                vector<int> prev;
                prev=ans.back();

                int lastIndex=prev.size(); // this will return the next index of the vector array

                
                //  creating next array of 1+ size
                vector<int> temp(lastIndex+1);

                temp[0]=1;
                temp[lastIndex]=1;
                for(int j=0;j<lastIndex-1;j++){
                    temp[j+1]=prev[j]+prev[j+1];
                }
                
                ans.push_back(temp);
            }
        }
        return ans;
    }
};