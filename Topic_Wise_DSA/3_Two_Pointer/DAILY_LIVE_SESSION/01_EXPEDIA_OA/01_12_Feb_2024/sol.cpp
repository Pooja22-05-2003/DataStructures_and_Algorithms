// Observation:- Biggest number in array “a”; has the maximum chance of being a valid pair with the smallest number in b 

// -> If even that doesn't not work then answer is 0 

// How can we visualize this problem better 

// By sorting the array because we are comparing elements and that makes it seem easier to visualize. 


// ->Bigger element of a already have good chance to win; so to increase the number of valid pairs lets first try to make small elements of a win first 

// First element of a should competed with first element of b to have maximum chance of a > b 


// TC :- O(NlogN + NlogN + N + N) = O(2*(NlogN + N)) = O(NlogN + N) = O(NlogN) 

// SC=Space used after sorting in the algorithm is O(1) but internal space is needed for sorting the arrays and its O(x) in C++ ; O(y) in Java ; O(g) in Py for inbuilt libraries in 
// the languages. If you implement the sorting algorithm on your own then it will be the space used by that sorting algorithm.

#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>a , vector<int>b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0;
    int j=0;
    int count=0;
    while((i<n )&& (j<n))
    {
        if(a[i]>b[j]) 
        {
            count++;
            i++;
            j++;
        }
        else 
        {
            i++;
        }
    }

    return count;
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

    vector<int>a(n);
    vector<int>b(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    cout<<solve(n,a,b);
	return 0;
}
	

/*
input1 :
3
1 2 2
2 1 1

Output 1:
2

input2 :
4
9 8 7 6
10 11 8 16

Output2:
1

*/

