// time taken : 00:30:12



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
    void helper(TreeNode * root , string &temp){
        if(root->left==NULL && root->right==NULL){
            return;
        }
        else {

            
            if(root->left!=NULL && root->right==NULL){
               
                temp+="(";
                temp+=to_string(root->left->val);
                helper(root->left,temp);
                temp+=")";
            }
            else if (root->left==NULL && root->right!=NULL){
              
                temp+="(";
                temp+=")";
                temp+="(";
                temp+=to_string(root->right->val);
                helper(root->right,temp);
                temp+=")"; 

            }

            else {
            
                temp+="(";
                temp+=to_string(root->left->val);
                helper(root->left,temp);
                temp+=")";
                temp+="(";
                temp+=to_string(root->right->val);
                helper(root->right,temp);
                temp+=")"; 
            }


        }


    }
    string tree2str(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        else {
        string ans="";
        ans+=to_string(root->val);
        helper(root,ans);
        return ans;
        }
        

    }
};