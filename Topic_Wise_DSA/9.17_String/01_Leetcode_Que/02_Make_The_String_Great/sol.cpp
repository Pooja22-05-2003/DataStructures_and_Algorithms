class Solution {
public:
    string makeGood(string s) {
        string ans="";
        if(s.size()==1) return s;
        if((s[0]!=s[1]) && ((s[0]==tolower(s[1]) || (s[0]==toupper(s[1]) ))))
        {
            // skip the first character
              s.erase(0,2);
           
        }
      
       int i=1;
        while(i<s.size())
        {
            if((s[i-1]!=s[i]) && ((s[i-1]==tolower(s[i]) || (s[i-1]==toupper(s[i]) ))))
               {
                   // skip both
               
                s.erase(i-1,2);
                cout<<"i:"<<i<<" s:"<<s<<endl;
                i=1;
              
               }
            else i++;
            
            
        }
               
        return s;
    }
};