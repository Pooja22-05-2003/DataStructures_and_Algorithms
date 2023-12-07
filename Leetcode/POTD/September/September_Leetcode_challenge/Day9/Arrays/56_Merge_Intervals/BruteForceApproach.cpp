//  For merging , we need to iterate like taking O(n2)

// **** First u need to sort the array 
//  First starting with 0th index , compare from 1 to n-1 and then if we find any interval which is merging , so merge that 
//  After that update the last index of the array with the maximum value of the merged and the last value.
//  check the last interval in the answer vector 
//  And now if we are doing merging again then check that if the first element of the current interval is samller  then previous interval  end then only do merging of that interval, if this condition is not satifying then simply continue.


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            auto curr=intervals[i];
            int first=curr[0];
            int second=curr[1];

            // *** Here earlier u are doing wrong and whenever i=0 , u are doing merging and pushing that as it is in your answer vector , but even when i==0 u need to merge the overlapping intervals , then only push that.
            if(!ans.empty() && second<=ans.back()[1]){
                    continue;
                    
                }
            else {
            for(int j=i+1;j<n;j++){
                auto temp=intervals[j];
                int tempFirst=temp[0];
                int tempSecond=temp[1];

                //  If the answer vector is empty , then u need to do the merging
               
               if(tempFirst<=second)
                  second=max(second,tempSecond);
               else break;
               

                }
                 ans.push_back({first,second});
                
            }
        }

        return ans;
    }
};


