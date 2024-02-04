//tc= O(n3)
// sc=O(n)
class Solution {
public:

    bool check(string s, string t, int st, int end)
    {
       
        unordered_map<int,int>map_s;

        for(int i=st;i=end;i++)
         map_s[s[i]]++;
       

        for(int i=0;i<t.size();i++)
        {
            if(map_s.find(t[i])!=map_s.end())
            {
                // continue;
            }
            else return false;
        }

        return true;
    }
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(n>m) return "";

        if(n==m)
        {
            // the first can be that both the string are equal , that return that string
            if(s==t) return s;
             else return "";
            // else return empty string           
        }

        // it means that the length of the string s> length of the string t.
        int minlen=INT_MAX;

        // check for all the possible substring , if it was good , then update the maxlen with comparsion
        string ans="";
        for(int i=0;i<m;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(check(s,t,i,j)==true){
                    int len=(j-i)+1;
                    if(len<minlen)
                    {
                        minlen=min(minlen,len);
                        cout<<"i:"<<i<<" J:"<<j<<endl;
                        ans=s.substr(i,len);
                    }
                }
            }
        }

        return ans;
    }
};