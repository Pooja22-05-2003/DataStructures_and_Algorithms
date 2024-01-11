// As in 1 minute , we can traverse all the adajcent nodes, so we need to create one graph , which will store all the adjacent nodes in adjacecncy matrix.
// Call bfs to find the smallest time to cover the whole graph.

// TC=O(n)
// SC=O(n)
class Solution {
public:

    void createGraph(TreeNode* root, int start , unordered_map<int,vector<int>> &adjacecny){
        queue<pair<TreeNode*,int>>q;

        q.push({root,-1});

        while(!q.empty()){
            TreeNode* currNode=q.front().first;
            int parent=q.front().second;
            q.pop();
            if(parent==-1) {
                 if(currNode->left) q.push({currNode->left,currNode->val});
                 if(currNode->right) q.push({currNode->right,currNode->val});
                 continue;
            }
            adjacecny[parent].push_back(currNode->val);
            adjacecny[currNode->val].push_back(parent);
            
            if(currNode->left) q.push({currNode->left,currNode->val});
            if(currNode->right) q.push({currNode->right,currNode->val});
        }
    
    }
    int amountOfTime(TreeNode* root, int start) {
        // We can' create here adjacnecy list, which we create normally in graph , because here we not know the exact nodes value, as it is not continuous, So unordered_map to store the values.
        unordered_map<int,vector<int>> adjacecny;
        createGraph(root,start,adjacecny);
        queue<pair<int,int>> q;
        unordered_map<int,bool>vis;
        int t=0;
        vis[start]=true;
        q.push({start,0});
         while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int time = it.second;

            t=max(t,time);

            for(auto it:adjacecny[node]){
                if(!vis[it]){
                    q.push({it,time+1});
                    vis[it]=true;
                }
            }
        }
        return t;

    }
};