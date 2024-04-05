

class Solution {
public:
    int maxDepth(string s) {
        int maxdepth=0;
        stack<char>st;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') 
            {
               char curr=s[i];
               st.push(curr);
                // cout<<"size:"<<st.size()<<endl;
                
            // Max only work for same type of datatype
               maxdepth=max(maxdepth,int(st.size()));
            }
            else if (s[i]==')') 
            {
                st.pop();
            }
        }
        return maxdepth;
       }
    
};







