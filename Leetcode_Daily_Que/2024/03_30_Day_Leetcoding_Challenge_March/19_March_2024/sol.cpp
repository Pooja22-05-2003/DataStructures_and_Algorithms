class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> arr(26,0);
        for(char c : tasks)
            arr[c - 'A']++;
        sort(arr.begin(), arr.end());
        int chunk = arr[25] - 1;
        int idleSpots = chunk * n;
        for(int i = 24; i >= 0; i--)
            idleSpots -= min(chunk, arr[i]);
        return (idleSpots < 0) ? tasks.size() : (idleSpots + tasks.size());
    }
};