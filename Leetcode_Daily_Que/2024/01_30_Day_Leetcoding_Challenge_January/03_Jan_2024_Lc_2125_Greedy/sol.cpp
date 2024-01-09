/*
Greedy Algorithm :
1. We can iterate throught the bank matrix and can maintain the previous count (Security devices in the prev row)-> We will updated the prev count only if we have curr count >=0 .
2. Now lets say row1 has 2 devices and row 3 has 3 devices, then each one of the previous row can pair up with each one of the next row.
3. Total Laser Beam between two rows=n*m
4. Do add in the answer. ans+=(n*m)
5. Return the final ans after all the iteration.
*/

// TC=O(n*m)
// SC=O(1)
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev_count=0;    
        int ans=0;
        for(int i=0;i<bank.size();i++){
            int curr_count=0;
            for(int j=0;j<bank[0].size();j++){
                if(bank[i][j]=='1') curr_count++;
            }
            // cout<<"curr_count:"<<curr_count<<" prev_count:"<<prev_count<<endl;
            if(curr_count>0){
                ans+=(prev_count*curr_count);
                prev_count=curr_count;

            }
            cout<<"ans:"<<ans<<endl;
        }

        return ans;
    }
};