// TC=O(n) // n is the size of the string
// SC=O(n) // recusrion stack space
/*
Time Complexity (TC): The time complexity is O(n), where n is the size of the string. This is because the function 
iterates through each character of the string exactly once, either by advancing the index ind in each recursive call
 or by reaching the base case when ind is greater than or equal to the size of the string.

Space Complexity (SC): The space complexity is also O(n) due to recursion stack space. 
Each recursive call adds a new frame to the call stack until the base case is reached.
 Since there can be at most n recursive calls (one for each character in the string), 
 the maximum space required on the call stack is proportional to the size of the string.

*/
#include <bits/stdc++.h>
using namespace std;

void PrintReverseString(string s,int ind)
{
    // Base Case 
    if(ind>=s.size()) return ;

    PrintReverseString(s,ind+1);
    cout<<s[ind];
    
}
void solve( string s)
{
    PrintReverseString(s,0);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********
    string s;
    cin>>s;
    solve(s);
   
    return 0;
}

/*
input1 :
Hello

Output 1:
olleH


input1 :
Pooja

Output 1:
ajooP





*/
