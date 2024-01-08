/*
Brute Force Approach.
1.Generate all the substring using 2 for loops and check whther substring is pallindrome or not.
2. If it is pallindrome, then calculate its len, If its len is more than maxLen, then update the maxlen and finalSt ,FinalEnd.
3. After iterating through all the substrigs, print the maximum length substring and its len.

*/


// O(n2*n) // O(n2)=> O(n3) to gernerate all the substring and O(n)-> to check all the substring whether it is pallindrome or not.
// SC=O(1)
#include<bits/stdc++.h>
using namespace std;
void Print(string s , int st , int end){
    for(int i=st;i<=end;i++){
        cout<<s[i];
    }
    cout<<endl;
}
bool check_Pallindrome(string s, int st , int end){
    int i=st;
    int j=end;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
void solve(string s){
    int maxlen=0;
    int len=1;
    int FinalSt;
    int FinalEnd;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            bool isPallindrome=check_Pallindrome(s,i,j);
            if(isPallindrome==true){
            int len=j-i+1;
            if(len>maxlen){
                FinalSt=i;
                FinalEnd=j;
                maxlen=max(maxlen,len);
            }
            }
        }
    }

    cout<<"MaxLen:"<<maxlen<<" Pallindromic Subsequence is :";
    Print(s,FinalSt,FinalEnd);

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
    solve(s);
	return 0;
}
	


/*
// input1 :
forgeeksskeegfor


// output1:
MaxLen:10 Pallindromic Subsequence is :geeksskeeg
1


// input 2 :
Geeks


// output 2:
MaxLen:2 Pallindromic Subsequence is :ee


input3:



output3:

*/


