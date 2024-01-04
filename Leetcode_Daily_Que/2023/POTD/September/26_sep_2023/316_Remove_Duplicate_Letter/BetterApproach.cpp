// ✨✨✨✨

//  Time Complexity=O(3*N)
// Space Complexity=O(3*N)

/*
-> 1)Here we need 3 extra datastructure
-> 2)One is lastIndex array , that will store the last index of all the character
-> 3)Second that one visited array -> Mark those character true, which u have decided to take it as final in the sequence
-> 4)Thirs take one stack, where u will do these operations.

-> 5)✅If we are finding any next character which is smaller then top of the stack && that top of the stack element also present in the array afterwards(we can check this using lastIndex array). then we can pop that element from the stack && also mark in the seen array false.


-> 6)Whenever we are pushing anything to the stack mark it to true, and if 5th point is satifying then pop from the stack but also mark it false in the visted array

*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26,0);

        vector<bool>vis(26,false);

        stack<char> st;

        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            lastIndex[index]=i;
        }

        for(int i=0;i<s.size();i++){
            int curr=s[i]-'a';

            //  this is ensuring that if we had taken one element in the array , then u can't take that again , because in question it is said that we need to remove that element
            if(vis[curr]==true) continue;

            while(st.size()>0 && st.top()>s[i] && lastIndex[st.top()-'a']>i){
                vis[st.top()-'a']=false;
                st.pop();
            }

            st.push(s[i]);
            vis[curr]=true;
        }

        string ans="";
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }


        reverse(ans.begin(),ans.end());
        return ans;
    }

};