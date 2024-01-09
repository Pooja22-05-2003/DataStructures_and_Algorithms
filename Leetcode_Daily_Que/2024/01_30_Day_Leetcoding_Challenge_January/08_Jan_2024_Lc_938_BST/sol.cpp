/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//  TC=O(N)
// SC=O(N) skewed Tree (Recursion space)
class Solution {
public:
    void preorder(TreeNode * root , int low , int high , int &sum){
        if(root==NULL) return ;
        if(root->val>=low && root->val <=high) sum+=root->val;
        preorder(root->left,low,high,sum);
        preorder(root->right, low , high , sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        preorder (root,low,high,sum);
        return sum;
    }
};