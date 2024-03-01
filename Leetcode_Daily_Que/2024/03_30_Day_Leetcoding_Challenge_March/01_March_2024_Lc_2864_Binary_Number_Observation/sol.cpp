/*
TC=O(n)
SC=O(1)
*/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1=0;
        int cnt0=0;
        for(auto it :s){
            if(it=='1') cnt1++;  
            else cnt0++;          
        }

        string ans="";
        if(cnt1==1)
        {
            for(int i=0;i<s.size();i++)
            {
                if(i==(s.size()-1)) ans+='1';
                else ans+='0';
            }
              cout<<"ans:"<<ans<<endl;
        }
      
        else 
        {
            int tempCnt1=cnt1-1;
            int ndextInd=tempCnt1;
            int i=0;
            while(tempCnt1>0)
            {
                ans+='1';
                tempCnt1--;
                i++;
            }

            i=ndextInd;
            while(i<(s.size()-1))
            {
                ans+='0';
                i++;
            }
            ans+='1';
            
        }

        return ans;
    }
};