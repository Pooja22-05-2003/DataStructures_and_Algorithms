/*

New Question.-> Same as above ; but you are allowed to take a maximum of only 2 
consecutive numbers ; not more than that->(3 numbers should not be consecutive.)

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

 
    for(int i=2;i<=n;i++){

        dpa[i]=arr[i][1] +  max(dpb[i-1],dpc[i-1]);
        int temp=arr[i][1]+(arr[i-1][1]+max(dpb[i-2],dpc[i-2]));
        dpa[i]=max(dpa[i],temp);

        dpb[i]=arr[i][2] + max(dpa[i-1],dpc[i-1]);
        int tempp=arr[i][2]+(arr[i-1][2]+max(dpa[i-2],dpc[i-2]));
        dpb[i]=max(dpb[i],tempp);

        dpc[i]=arr[i][3] + max(dpa[i-1], dpb[i-1]);
        int temppp=arr[i][3]+(arr[i-1][3]+max(dpb[i-2],dpa[i-2]));
        dpc[i]=max(dpc[i],temppp);
    }
    for(int i=1;i<=n;i++){
        cout<<"dpa[i]:"<<dpa[i]<<" dpb[i]:"<<dpb[i]<<" dpc[i]:"<<dpc[i]<<endl;
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
dpa[i]:6 dpb[i]:7 dpc[i]:8
dpa[i]:16 dpb[i]:16 dpc[i]:11
dpa[i]:18 dpb[i]:21 dpc[i]:18
dpa[i]:28 dpb[i]:29 dpc[i]:27
dpa[i]:33 dpb[i]:34 dpc[i]:37
dpa[i]:39 dpb[i]:40 dpc[i]:41
dpa[i]:48 dpb[i]:46 dpc[i]:41

48
*/


