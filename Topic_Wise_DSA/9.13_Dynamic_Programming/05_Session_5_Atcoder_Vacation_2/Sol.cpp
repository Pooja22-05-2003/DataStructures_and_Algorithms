/*
Problem in 2-3 lines.
Given 2D array , having 3 col.
On each day u need to do work and it will give u .....x amount of happiness. But U can't do same work on 2 or more consecutive day.
As there are only 3 columns , then u can have only 3 work.I u choose to do 1st work today ....which will give u x amount of happiness,
u can' do that 1st work on next day. Now on next day ...u have only 2 options. whether to do the 2nd work or 3rd work.

Now, U need to achieve the maximum happiness.



SOLUTION:
-> As this is not a greedy problem and it's a dp problem because , consective same work is not allowed.
-> And on the 1st day , u don't have the knowledge of the future or the 2nd day happiness.
-> So, u need to find all the possiblities and pic the best answer from all of them.
-> For this u need 3 arrays.
-> dpa[i]= It tells the maximum happiness till index i , if u decided to pic the arr1[i](1st work) on the ith day.
-> dpb[i]= It tells the maximum happiness till index i , if u decided to pic the arr2[i](2nd work) on the ith day.
-> dpc[i]= It tells the maximum happiness till index i , if u decided to pic the arr3[i](3rd work) on the ith day.

-> Run a for loop and calculate till dp[n]
-> Now maximum of (dpa[n],dpb[n],dpc[n]) will be your answer.
*/


#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> arr , int n ){

    vector<int> dpa(n+1,0);
    vector<int> dpb(n+1,0);
    vector<int> dpc(n+1,0);

    dpa[1]=arr[1][1]; // 10
    dpb[1]=arr[1][2]; // 40
    dpc[1]=arr[1][3]; // 70

    //dpa[2]=90
    // dpa[3]=
    for(int i=2;i<=n;i++){
        // it means u are taking the 1st el and finding maxans from dpb[i-1] and dpc[i-1]
        dpa[i]=arr[i][1]+max(dpb[i-1],dpc[i-1]);
        // it means u are taking the 2nd el and finding maxans from dpa[i-1] and dpc[i-1]
        dpb[i]=arr[i][2] + max(dpa[i-1],dpc[i-1]);
        // it means u are taking the 3rd el and finding maxans from dpa[i-1] and dpb[i-1]
        dpc[i]=arr[i][3] + max(dpa[i-1], dpb[i-1]);
    }

    return max(dpa[n],max(dpb[n],dpc[n]));
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

    vector<vector<int>> arr(n+1,vector<int>(3+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>arr[i][j];
        }
    }

    cout<<solve(arr,n);
	return 0;
}
	


/*
// input1 :
3
10 40 70
20 50 80
30 60 90


// output1:
210


// input 2 :
1
100 10 1


// output 2:
100


input3:
7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1


output3:
46
*/


