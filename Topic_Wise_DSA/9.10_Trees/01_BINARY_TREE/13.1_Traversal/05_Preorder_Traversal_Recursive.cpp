#include "binaryTreeClass.h"
#include<bits/stdc++.h>

using namespace std;

void RecursivePreorder(BinaryTree* root)
{
    if(root==NULL)
    {
        return ;
    }

    // root, left , right
    cout<<root->data<<" ";
    RecursivePreorder(root->left);
    RecursivePreorder(root->right);
}

int main()
{
    BinaryTree*root=new BinaryTree(1);
    BinaryTree*leftNode=new BinaryTree(31);
    BinaryTree*rightNode=new BinaryTree(33);
    root->left=leftNode;
    root->right=rightNode;

    RecursivePreorder(root);

}

/*
Output :
1 31 33 
*/