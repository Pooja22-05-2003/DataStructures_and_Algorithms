// TC=O(n1,n1) // n1 = It is the length of the tree 
// SC=O(T1,T2) // T1 and T2 are the vectors spaces used .... and also there is a space of the reursion.

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
    void Inorder(TreeNode * root,vector<int> &v){
        // left root right 
        if(root==NULL) return;
        if(root->left) Inorder(root->left,v);
        if(root->left==NULL && root->right==NULL) v.push_back(root->val);
        Inorder(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        Inorder(root1,v1);
        Inorder(root2,v2);
        if(v1.size()!=v2.size()) return false;
        else 
       {
        for(int i=0;i<v1.size();i++){
            
                if(v1[i]==v2[i]) {}// do nothing;
                else return false;
            
        }
        }
        return true;
    }
};