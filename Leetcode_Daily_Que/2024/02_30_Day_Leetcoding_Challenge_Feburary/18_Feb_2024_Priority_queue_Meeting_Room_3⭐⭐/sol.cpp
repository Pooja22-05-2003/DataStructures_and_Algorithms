#define ll long long

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<ll,vector<ll>,greater<ll>> pq1;   // Rooms No  Available available
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq2; //busy (on going meetings)
        
        
        vector<ll> roomCount(n,0);
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++) pq1.push(i);
        for(auto meet : meetings){
            ll start=meet[0], end=meet[1];
            while(!pq2.empty() and start>=pq2.top().first){

                // make this room free and put the room number in the available rooms
                pq1.push(pq2.top().second);
                pq2.pop();
            }
            if(pq1.size()){
                ll room=pq1.top();
                pq1.pop();

                // schedule the current meeting in the available room
                pq2.push({end,room});
                roomCount[room]++;
                continue;
            }


            // if the compiler come here it means that we do not have available room
            // now for now no room is free, so the next meeting will schedule when the earliest finsih time meeting will end.
            ll nextEnd=pq2.top().first;
            ll nextRoom=pq2.top().second;
            pq2.pop();
            pq2.push({nextEnd+(end-start),nextRoom});
            roomCount[nextRoom]++;
        }
           return max_element(roomCount.begin(),roomCount.end())-roomCount.begin(); 
    }
};