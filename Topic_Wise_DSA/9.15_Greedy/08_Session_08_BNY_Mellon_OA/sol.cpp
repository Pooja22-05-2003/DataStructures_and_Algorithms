/*
Approach:
Que in 1 Line :
Given a 2D array , having 2 column and n rows.
Each row contain  a nurse detail. (nurse id and Leave time).
Find out the nurse emplyee number who works lonest hour in single shift.


1. Iterate thorugh the array and and find the workign hour of the current nurse, for this u need to maintain the end time of the previous nurse.
2. If the working hour is greater than the maximum value , then update the maximum value and the answer variable with the current nurse id.
*/

// TC=O(n)
// SC=O(1)
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>arr, int n)
{
    int ans=-1;
    int maxTime=INT_MIN;
    int st_time=0;
    for(int i=1;i<=n;i++)
    {
        int emp_id=arr[i][1];
        int endTime=arr[i][2];
        int work_Hr= (endTime-st_time);
        cout<<"work_Hr:"<<work_Hr<<" Nurse_id:"<<emp_id<<endl;

        if(work_Hr>maxTime)
        {
            maxTime=work_Hr;
            ans=emp_id;
        }
        st_time=endTime;

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
    //

    //*********

    int n;
    cin >> n;

    vector<vector<int>>arr(n+1,vector<int>(3,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2;j++)
        {
            cin>>arr[i][j];
        }
    }

  
    int ans = solve(arr, n);
    char a=ans+'a';
    cout << "ans:"<<ans<<" Albhabet_Id:"<<a<< endl;

    return 0;
}

/*
input1 :
4
0 3
2 5
0 9
1 15


Output 1:
work_Hr:3 Nurse_id:0
work_Hr:2 Nurse_id:2
work_Hr:4 Nurse_id:0
work_Hr:6 Nurse_id:1
ans:1 Albhabet_Id:b


input2 :
3
0 2
1 3
0 7

Output2:
work_Hr:2 Nurse_id:0
work_Hr:1 Nurse_id:1
work_Hr:4 Nurse_id:0
ans:0 Albhabet_Id:a


Input 3:
5
0 1
0 3
4 5
5 6
4 10

Output3:
work_Hr:1 Nurse_id:0
work_Hr:2 Nurse_id:0
work_Hr:2 Nurse_id:4
work_Hr:1 Nurse_id:5
work_Hr:4 Nurse_id:4
ans:4 Albhabet_Id:e



*/
