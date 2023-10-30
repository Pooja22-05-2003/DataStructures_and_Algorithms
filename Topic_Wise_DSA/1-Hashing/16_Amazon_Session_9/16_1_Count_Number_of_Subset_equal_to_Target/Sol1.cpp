// TC=O(N)
// SC= O(N)

#include <bits/stdc++.h>
using namespace std;

int solve(string &s , string &t){
    unordered_map<char,int> map;
    for(int i=0;i<s.size();i++){
        map[s[i]]++;
    }

    int ans=0;
    int TargetSize=t.size();
    bool flag=true;
    while(flag){
         int count=0;
        for(int i=0;i<t.size();i++){
           
            if(map[t[i]]>0 ){
                count++;
                map[t[i]]--;
                // cout<<"count:"<<count<<" Target Size " <<TargetSize<<endl;
                if(count==TargetSize) 
                {
                    // cout<<"hi"<<endl;
                    ans++;
                    break;
                }
            }
            else 
            {
                flag=false;
                break;
            }
        }
       
    }

 
    return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********

    //*********
   string s;
   cin>>s;
   string t;
   cin>>t;
   cout<<solve(s,t)<<endl;

}






/*
input :
mononom
mon

output :
2

input2 :
abacbc
bca

output :
2


input 3:
abdadccacd
edac

output :
0

*/




