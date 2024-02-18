/*
Approach:
1. We need to keep atleast 1 occurence of all the characters.
2. While Iterating from the arr from start, we can remove any character at index i only if its occurence also present after index 'i'
else , we need to forcefullly keep that element.
3. Which Data Structure???🤔---> As we need to remove characters, we can' remove in arr , so think of stack(Monotonic Stack).
4. At index i if that character is bigger than the top most element of the stack, then its ok, push that.
5. But if it is smaller , try to pop the topmost element till the topmost element of the stack is not smaller than the current element.
Rememeber, we can remove any character , it is present afterwards also.[For that we will keep , one unordered map, where we will store the last index of all the characters].


*/

#include<bits/stdc++.h>
using namespace std;

string solve(string s){
    string ans="";

    unordered_map<char,int>tracker; // track the last index of the characters

    for(int i=0;i<s.size();i++)
    {
        tracker[s[i]]=i;
    }

    
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(st.empty() || (st.top()<s[i])) st.push(s[i]);
        else {

            cout<<"i:"<<i<<endl;
            while((!st.empty()) && (st.top()>s[i]))
            {
                cout<<"i:"<<i<<" st.top():"<<st.top()<<endl;
                cout<<"st.size():"<<st.size()<<endl;
                int LastIndex=tracker[st.top()];
                cout<<"LastIndex:"<<LastIndex<<endl;
                if(LastIndex>i)
                {
                    cout<<"s[i]:"<<s[i]<<endl;
                    // we can pop safely
                    st.pop();
                }
                else break;
            }
            if(st.empty()) st.push(s[i]);
            else if(s[i]!=st.top()) st.push(s[i]);
        }
    }

    unordered_map<char,int>mp;
    while(!st.empty())
    {
       int el=st.top();
       if(mp.find(st.top())==mp.end())
       {
       ans+=st.top();
       mp[st.top()]=1;
       st.pop(); 
       }
    }
    reverse(ans.begin(),ans.end());

    return ans;
  
  
}  


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********


    string s;
    cin>>s;    
   
    cout<<solve(s)<<endl;

	return 0;
}
	

/*
input1 :
bbacdbdd


Output 1:
acbd



input2 :
aabcb




Output2:

abcb ❌❌// output is : abc 


*/



