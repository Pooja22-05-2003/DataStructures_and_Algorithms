/*
// TC=O(nlogn)
// SC=O(n)

Its mentioned in the question that mice 1 will need to select 'k' cheese and mice 2 can select the remaining cheese. We need to select the 'k' cheese in such a way that the reward will be maximum.
I am using a priority queue <difference between reward1[i] and reward2[i], reward1[i], reward2[i]>
By default the heap will be created based on the first element. It can be said that whenever we select reward1 'k' times, the one with maximum difference will be optimal.
So we select the first 'k' elements from reward1 and then the remaining elements from reward2 will give us the optimal answer.


// Reward1[i]=> Iske points bas mouse 1 ko milenege, and wo hi ise eat kr skte hai.
// Reward2[i]=> Second mouse ko milenge bas

// To ek condition given hai ki, mouse1 bas k types of cheese eat kr skta hai, to use waise cheese pick krne chahiye, jinme reward1[i]-reward2[i] maximum diff ho.
*/
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size();
        priority_queue<vector<int>>pq;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int diff=reward1[i]-reward2[i];
            pq.push({diff,reward1[i],reward2[i]});
        }
        
        while(!pq.empty() && k--)
        {
            ans+=pq.top()[1];
            pq.pop();
        }
        
        while(!pq.empty())
        {
            ans+=pq.top()[2];
            pq.pop();
        }
        
        return ans;
        
    }
};