/*
Time complexity: O(n*logk) where k is no. of ladders because heap size would always be k.
Space complexity: O(n)
*/
class Solution {
public:
    int furthestBuilding(vector<int>& arr, int bricks, int ladders) {
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<n-1;i++)
        {
            int diff=(arr[i+1]-arr[i]);
            
            if(diff<=0) continue;
            else 
            {
                // push the elements till the ladder size
                pq.push(diff);
                
                if(pq.size()>ladders)
                {
                    // use the brick for smaller size jump; which is store in the top of the priority queue, because we used min priority queue
                    int x=pq.top();
                    pq.pop();
                    bricks-=x;
                    
                }
                
                // if  no remaining bricks left, then return the curr index
                if(bricks<0) return i;
            }
        }
        
        // if we are able to reach the last building then return the last index.
        return n-1;
    }
};