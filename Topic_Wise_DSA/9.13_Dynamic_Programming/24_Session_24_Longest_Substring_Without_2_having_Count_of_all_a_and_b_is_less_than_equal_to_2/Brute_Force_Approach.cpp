/*
Brute Force solution 
1. check all the substring and is the substring is valid to the given condition,
   then do update the maximum length of the substring with the current length of the substring


*/

// TC= O(n3)
// SC= O(1)
#include<bits/stdc++.h>
using namespace std;
bool  checkValid(string s , int i, int j){
    int cnta=0;
    int cntb=0;

    for(int p=i;p<=j;p++){
        if(s[p]=='a'){
            cnta++;
            cntb=0;
        }

        if(s[p]=='b') {
            cntb++;
            cnta=0;
        }

        if(cnta>2 || cntb>2) return false;
    }
    return true;
}
int  solve(string s) 
{
    // check for all the substring 
    int n=s.size();
    int maxlen=0;
    int len=0;

    // O(n2)
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            // O(n)
            if(checkValid(s,i,j)==true){
                len=(j-i+1);
                maxlen=max(maxlen,len);
            }
        }
    }
   
   return maxlen;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********

   string s1;
   cin>>s1;

    cout<<solve(s1);

	return 0;
}
	


/*
// input1 :
aabbaaaaabb


// output1:
6

// input 2 :
aabbaabbaabbaaa

// output 2:
14



*/