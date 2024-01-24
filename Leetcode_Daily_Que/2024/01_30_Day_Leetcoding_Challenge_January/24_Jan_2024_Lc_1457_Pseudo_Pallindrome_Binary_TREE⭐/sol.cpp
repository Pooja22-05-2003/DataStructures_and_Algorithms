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
class Solution {
public:
    int solve(TreeNode* root, unordered_map<int,int>&freq)
    {
        if(!root) return 0;
        freq[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
            int cnt=0;
            for(auto it : freq)
            {
                if(it.second%2==1) cnt++;
            }
            freq[root->val]--;
            if(cnt<=1) return 1;
            else return 0;
        }

        int left=solve(root->left,freq);
        int right=solve(root->right,freq);
        freq[root->val]--;
        return left+right;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>freq;
        return solve(root,freq);
    }
};