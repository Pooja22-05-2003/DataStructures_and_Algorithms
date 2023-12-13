/*
Approach:
✨ Optimal approach

    1. Create two hash array , first hash array contain the count of continuos 0 at particular index i
    2. Similarly the 2nd hash array contain the count of continuous 1 at particular index i
    3. In the 3rd iteartion travel the whole array, of s[i]=='0', then count number of zero in hash zero array= zero[i]
    4. then go zerop[i] index backward So, int ind=zero[i] , if that ind>=0 and one[ind]>=zero[i] then increment the ans count
    5. If s[ind]=='1', then count the number of one in hash one array=> one[i]


*/


// TC=O(n)
// SC=O(n)


#include <bits/stdc++.h>
using namespace std;

int solve(string s) {

    int ans=0;
    int n=s.size();
    vector<int> zero(n+1,0);
    vector<int> one(n+1,0);

    if(s[0]=='0'){
        zero[0]=1;

    }
    else {
        one[0]=1;
    }

    // Making the zero hash array
    for(int i=1;i<n;i++){
        if(s[i]=='0'){
            zero[i]=zero[i-1]+1;
        }
        else {
            zero[i]=0;
        }
    }

    for(int i=1;i<n;i++){
        if(s[i]=='1'){
            one[i]=one[i-1]+1;
        }
        else {
            one[i]=0;
        }
    }


    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            int count_zero=zero[i];
            int move_back=zero[i];
            int ind_one=i-move_back;

            if(ind_one>=0 && one[ind_one]>=zero[i]) ans++;
        }

        else 
        {
            int count_one=one[i];
            int move_back=one[i];
            int ind_zero=i-move_back;

            if(ind_zero>=0 && zero[ind_zero]>=one[i]) ans++;
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
    // 1-- based indexing are used here

    string s;
    
    cin>>s;
    cout<<solve(s);;
   
}






/*

input1 :
000111000


output1:
6

input 2 :


output 2:


*/

