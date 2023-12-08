/*
Approach:
Observation approach just write in code format.
whatever question is telling u to do
*/


// TC=
// SC=


#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> arr,int n,int max_packet,int rate , int maxtime) {
   int drop_packet=0;
   int totalpacket=0;

   int t=arr[0][0];
   int i=0;
   while(t<=maxtime && i<n){
    int curTime=arr[i][0];
    int curPacket=arr[i][1];
   
   totalpacket+=curPacket;
    if(i!=0){
        int prevTime=arr[i-1][0];
        int diff=curTime-prevTime;
        int packetremove=diff*rate;
        totalpacket=totalpacket-packetremove;
      
    }
    

    if(totalpacket>max_packet){
        drop_packet+=totalpacket-max_packet;
        totalpacket=totalpacket-drop_packet;
          
    }

    i++;
    t=curTime;
   }

     return drop_packet;
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

    int n;
    cin>>n;

    int max_packet;
    cin>>max_packet;

    int rate;
    cin>>rate;
   
    vector<vector<int>> arr(n,vector<int>(2,0));
    int max_time=-1;

   for (int i = 0; i < n; i++) {
    int time;
    int packet;
    cin >> time;
    cin >> packet;
    arr[i][0] = time;
    arr[i][1] = packet;
    max_time = max(max_time, time);  // Update max_time correctly after reading time
}


    cout<<solve(arr,n,max_packet,rate,max_time);
}






/*

input :
3
10
2
1 8
4 9
6 7



output:
4


*/

