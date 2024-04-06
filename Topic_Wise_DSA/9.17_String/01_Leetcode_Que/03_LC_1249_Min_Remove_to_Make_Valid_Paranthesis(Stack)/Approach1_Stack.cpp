// TC=O(n)
// SC=O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
          unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++)
        {
          
             if (s[i]=='(') 
            {
               
                    st.push(i);
               
                
            }
            else if(s[i]==')')
            {
                if(st.empty())
                {
                     //st.push(i);
                    mp[i]++;
                   
                   
                }
                 else 
                {
                   
                    st.pop();
                }
            
            }
        }
        
     
        while(!st.empty())
        {
            int ind=st.top();
            st.pop();
            mp[ind]++;
        }

        // traverse the string
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(i)==mp.end()) ans+=s[i];
        }
        return ans;
    
    }
};