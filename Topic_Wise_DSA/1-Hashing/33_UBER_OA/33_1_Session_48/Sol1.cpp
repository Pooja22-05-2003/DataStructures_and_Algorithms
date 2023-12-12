/*
Approach:
✨ Optimal approach


    valid sequence only have 4 patterns
    1. aaaaaabbbbbbbb
    2. bbbbbbbbbbbbb
    3. bbbbbbaaaaaaa
    4. aaaaaaaaaaaaa


*/


// TC=O(n)
// SC=O(n)


#include <bits/stdc++.h>
using namespace std;

int solve(string s) {

    int ans=INT_MAX;
    int n=s.size();
    int i=0;

    vector<int> prefix_a(n+3,0);
    vector<int> suffix_b(n+3,0);
    vector<int> prefix_b(n+3,0);
    vector<int> suffix_a(n+3,0);
 
    if(s[0]=='a'){
     
        prefix_b[0]=1;

    }
    else {
       
        prefix_a[0]=1;
       
    }

    // if(s[n-1]=='b'){
        
    //     suffix_a[n-1]=1;

    // }
    // else {
    //     suffix_b[n-1]=1;
       
    // }
   
    for(int i=1;i<n;i++){
        if(s[i]=='a'){ {
            prefix_a[i]=prefix_a[i-1];
            }
        }
        else{
            prefix_a[i]=prefix_a[i-1]+1;
        }
    }

     for(int i=n-1;i>=0;i--){
        if(s[i]=='b'){
            suffix_b[i]=suffix_b[i+1];
        }
        else{
            suffix_b[i]=suffix_b[i+1]+1;
        }
    }


    for(int i=1;i<n;i++){
        if(s[i]=='b'){
            prefix_b[i]=prefix_b[i-1];
        }
        else{
            prefix_b[i]=prefix_b[i-1]+1;
        }
    }

     for(int i=n-1;i>=0;i--){
        if(s[i]=='a'){
            suffix_a[i]=suffix_a[i+1];
        }
        else{
            suffix_a[i]=suffix_a[i+1]+1;
        }
    }

    

    for(int i=0;i<n;i++){
        // for pattern of type1
        // 1. aaaabbbbb
        // 2. bbbbbbbb
        int cost1=prefix_a[i]+suffix_b[i+1];

        // for pattern of type2
        // 1. aaaabbbbb
        // 2. bbbbbbbb
        int cost2=prefix_b[i]+suffix_a[i+1];

        ans=min(ans,min(cost1,cost2));


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
    // 1-- based indexing are used here

    string s;
    cin>>s;

    cout<<solve(s);;
   
}






/*

input1 :
bbaaabbbbb


output1:
2

input 2 :
bbababaaaabbbbbbbb

output 2:
4

*/

