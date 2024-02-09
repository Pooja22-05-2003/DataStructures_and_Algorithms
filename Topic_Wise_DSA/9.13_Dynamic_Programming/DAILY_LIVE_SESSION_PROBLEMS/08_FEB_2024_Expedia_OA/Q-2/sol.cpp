/*
Approach :
1. All the factors of string length can be the answer, and n can definitely be the answer, but u need to return the minimum lenght of the substring.
2. Check for all the factors try from smaller to lareger factor and whichever is able to make the original string from the substring, return that length.

*/

// TC :-  O(sqrt(N)*(N)*26) = 8*10^8 = < 10^8 —> It will not work -> 
// Passes 10 out of 12 test-cases. 

// SC=O(n)
#include<bits/stdc++.h>
using namespace std;
bool checkValidString(unordered_map<char,int>map1,unordered_map<char,int>map2)
{
     char curr='a';
     while(curr<='z')
     {
        if(map1[curr]!=map2[curr]) return false;
        curr++;
     }
     return true;
}
bool check(int windowSize,string s)
{
    int n=s.size();
    unordered_map<char,int>map1;
    unordered_map<char,int>map2;
    int i;
    for(i=0;i<windowSize;i++)
    {
        map1[s[i]]++;
    }

    int j=windowSize;
    int cnt=0;
    while(j<n)
    {
        map2[s[j]]++;
        cnt++;
        if(cnt==windowSize)
        {
            if(checkValidString(map1,map2))
            {
                // continue checking
                map2.clear();
                cnt=0;
            }
            else return false;
        }
        j++;
    }
    return true;
}
int solve(string s ){
	int n=s.size();
    int minlen=-1;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0) {
            if(check(i,s)==true)
            {
                return i;
            }
        }
    }

    return n;
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

    
    cout<<solve(s);
	return 0;
}
	


/*
// input1 :
bbaaababababaabb

Output :
4


// input 2 :
ababbaab

// output 2:
2

input3:
abcbcacba

output3:
3
*/