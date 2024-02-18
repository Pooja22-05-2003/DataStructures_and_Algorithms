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

// TC=O(n)
// SC=O(n)
#include<bits/stdc++.h>
using namespace std;

string solve(string s){
    string ans="";


    
    stack<char>st;
    unordered_map<char,int>count; // It will tell :-> After erasing the current character, the count is present afterward
    
    unordered_set<char>usedChar; // Which charcters i used upto the string
    
    for(auto it:s){ 
        count[it]++;
    }
    
    int n = s.length();
    
    for(int i=0;i<n;i++){
        
        // if lexicorgraphich maximum is asking in que :
        // use this  while(!st.empty() && st.top()<s[i] && count[st.top()]>=1)
        while(!st.empty() && st.top()>s[i] && count[st.top()]>=1){ // St.top() wala bigger,and o bad mai aata hai
            usedChar.erase(st.top()); // pehle ans mei use kiya tha....ab nahi chhaiye,....to removing it.
            st.pop();
        }
        
        if(usedChar.count(s[i])==0){ // If not used yet, then use it
            st.push(s[i]);
            usedChar.insert(s[i]);
        }
        count[s[i]]--;
    }
    

    
    while(!st.empty())
    {
       ans+=st.top();
       st.pop(); 
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

abc 


*/


