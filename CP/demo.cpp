// TC=O(N)
// SC=O(N)
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

