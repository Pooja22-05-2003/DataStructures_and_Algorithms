/*

Brute Force Approach:

1. First Break the questions.
2. Find the range of the days in which u can eat n cholcolates given to u.
3. In n days (if u eat daily 1 chococlate), then u can eat the whole choclate in n days. [ This is the maximum possible answer].
4. We need to find the minimum possible answer.
5. Let's start our loop from 1 to n . At which ever position (Your check function return true), that would be your answer.

*/


// TC=O(n)
// SC=O(1)
#include<bits/stdc++.h>
using namespace std;
bool check(int day,int No_Of_Chocolate ){
    // calculate the maximum number of chocolate u can eat with (day given)
    // if day is even
    int sum=0;
    if(day%2==0){
    int n1=day/2;
    int n2=day/2;

    int s1=(n1*(n1+1))/2;
    int s2=(n2*(n2+1)/2);

    sum=s1+s2;
    }
    else {
        int n1=day/2;
        int n2=(day/2)+1;
        int s1=(n1*((n1+1)/2));
        int s2=(n2*((n2+1)/2));

        sum=s1+s2;
    }

    if(sum>=No_Of_Chocolate) return true;
    else return false;


}
int  solve( int No_Of_Chocolate){
    // Asnwer will lie in some range

    int i=1;
    while(i<=No_Of_Chocolate){
        if(check(i, No_Of_Chocolate)==true){
            return i;
        }

        i++;
    }
    return No_Of_Chocolate;
  
}




int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********
	// int n;
    // cin>>n;


    int k;
    cin>>k;
    // vector<int> arr1(n+1);
    // for(int i=1;i<=n;i++){
    //     cin>>arr1[i];
    // }

    cout<<solve(k)<<endl;
	return 0;
}
	


/*
// input1 :
8

// output1:
5


// input 2 :
6

// output 2:
4

input3:


output3:


*/

