/*
Approach - 
1. Store the frequency of each element in the array.
2. Now Iterate throught each key value in the map and write check condition.
   -> for ex count of el=13 then if(count > 4 && (count%3==1) ) ans+=(((count-4)/3 )+ (4/2));
   -> else If count%3==0 || count%2==0 || count%3==2 any of the condition satifying then return the answer as -1;
   -> else if(count%3==0) ans+=count/3 and move the next iterator.
   -> else if (count%3==2) then add ans+=(count/3)+1 and move to the next iterator.
   -> else if (count%2==0) then add ans+=(count/2) and move to the next iterator.
3. After doing alll the iterations, return ans.
*/


class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        int ans=0;
        for(auto it : freq){
            // cout<<"key:"<<it.first<<" value:"<<it.second<<endl;
            int count=it.second;
            if(count > 4 && (count%3==1) ) ans+=(((count-4)/3 )+ (4/2));
            else if(count%3!=0 &&  count%2!=0 && count%3!=2) return -1;
            else {
                if(count%3==0) ans+=(count/3);
                else if (count%3==2) ans+=(count/3)+1;
                else if (count%3==1) ans+=(((count-4)/3 )+ (4/2));
                else if (count%2==0) ans+=(count/2);
            }
        }

        return ans;
    }
};