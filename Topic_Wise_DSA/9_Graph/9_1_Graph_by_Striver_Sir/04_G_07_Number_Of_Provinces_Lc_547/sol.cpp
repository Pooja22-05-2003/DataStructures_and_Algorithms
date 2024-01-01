// TC=O(V+2*E)
// SC=O(n)
class Solution {
public:
    void dfs(int st,vector<int>&vis, vector<int> adj[],int &ans){
        vis[st]=1;
        for(auto it : adj[st]){
            if(!vis[it]) dfs(it,vis,adj,ans);
        }
    }
    int dfsTraversal(int V, vector<int> adj[]){
        vector<int> vis(V,0);
        int ans=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
             ans++;
            dfs(i,vis,adj,ans);
            }
        }
        return ans;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        return dfsTraversal(n,adj);
    }
};