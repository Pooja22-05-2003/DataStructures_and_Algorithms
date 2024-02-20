/*
Approach:
1. For the String to not not contain "10" as the substring .
2. Try to convert the string into the any of the following 3 states.
     i-> 0000000000.... (0^n)
     ii-> 111111111.... (1^n)
     iii-> 000000111111 (0^n 1^n)
3. For this we can flip 0->1 or 1->0 any number of times.
4. Find the minimum number of flips required to make it a valid string.

*/


/*

*/

// TC=O(n)
// SC=O(n)
#include<bits/stdc++.h>
using namespace std;

int  solve(string s){
    int n=s.size();
    vector<int>prefix(n,0); // 000000 type 
    vector<int>suffix(n,0); //  11111..

    int cnt1=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') cnt1++;
        prefix[i]=cnt1;
    }

    int cnt2=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='0') cnt2++;
        suffix[i]=cnt2;
    }

    for(auto it : prefix) cout<<it<<" ";
    cout<<endl;

    for(auto it : suffix) cout<<it<<" ";
    cout<<endl;
    int ans=min(prefix[n-1],suffix[0]);

    // for string of type 000111
    for(int i=0;i<n-1;i++)
    {
        ans=min(ans,(prefix[i]+suffix[i+1]));
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


    string s;
    cin>>s;
   
    cout<<solve(s);

	return 0;
}
	

/*
input1 :
111000101000


Output 1:
1 2 3 3 3 3 4 4 5 5 5 5 
7 7 7 7 6 5 4 4 3 3 2 1 
5



input2 :
01110000001

Output2:
0 1 2 3 3 3 3 3 3 3 4 
7 6 6 6 6 5 4 3 2 1 0 
3


*/


