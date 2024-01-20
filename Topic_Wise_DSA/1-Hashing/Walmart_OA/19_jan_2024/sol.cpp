/*
Problem in simpler form:
1. Find the length of the character which are coming in all the n strings.
*/

// TC= O(26 + N*(N+26) + 26) = O(N*N + 26*N) 
// N*N <= 500000 
// 26*N = 2600000 = 2.6 * 10^6 < 10^8 

// SC=O(2*26)=> O(1)

// SC=O(N*3)

#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<string>s) {
    // Intitalliy,let the 
    int ans=0;
    unordered_map<char,int>final_ans;
    char temp='a';
    while(temp<='z'){
        final_ans[temp]=INT_MAX;
        temp++;
    }


    for(auto it : s){
        string currString=it;
        unordered_map<char,int>freq;
        for(int i=0;i<currString.size();i++){
            freq[currString[i]]=freq[currString[i]]+1;

        }

        // store the min freq in the final ans;

        char temp='a';
        while(temp<='z'){
        final_ans[temp]=min(final_ans[temp],freq[temp]);
        temp++;
        }
      

    }


    // store all the freq of char in the final ans, there can be more than one occurence of a single char in the final ans.
    char tt='a';
    while(tt<='z'){

       if(final_ans[tt]!=INT_MAX) ans=ans+final_ans[tt];
        tt++;
    }

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

    int n;
    cin>>n;

    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

   
    int ans=solve(n,s);
    cout<<ans<<endl;
    
	return 0;
}
	


/*
// input1 :
2
ab
cba


// output1:
2

Input2:
3
abcdef
xcxefd
vefc



// output 2:
3


input3:


output:


input4:

output: 



*/