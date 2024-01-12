// TC=O(n)
// SC=O(H) H is the height of the binary tree
class Solution {
public:
    pair<int,int> helper(TreeNode* root , int &ans){
        if(root==NULL) return {INT_MAX,INT_MIN};
        auto temp1 = helper(root->left,ans);
        auto temp2= helper(root->right,ans);

        int maxx=min(root->val,min(temp1.first,temp2.first));
        int minn=max(root->val,max(temp1.second,temp2.second));

        ans=max(ans, max(abs(root->val-maxx) , abs(root->val-minn)));
        return {maxx,minn};

    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        auto it = helper(root,ans);
        return ans;
    }
};