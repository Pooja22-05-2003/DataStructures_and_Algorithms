#include <iostream>
using namespace std;
template <typename T>
class BinaryTreeNode{

    public:
    T data;
    BinaryTreeNode <T>* left;
    BinaryTreeNode<T> * right;

    BinaryTreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }

};

BinaryTreeNode<int> * takeInput(){
    int rootData;
    cout<<"Enter  data:"<<endl;
    cin>>rootData;

    
    if(rootData==-1) return NULL;
    BinaryTreeNode <int> * root= new BinaryTreeNode <int> (rootData);
    BinaryTreeNode<int> * leftchild=takeInput();
    BinaryTreeNode<int> * rightchild=takeInput();
    root->left=leftchild;
    root->right=rightchild;
    return root;
}



void printLevelWise(BinaryTreeNode<int>*root){
    cout<<" root: "<<root->data<<" ";
    if(root->left->data !=-1) cout<<"L: "<<root->left->data;
    if(root->right->data!=-1) cout<<"R: "<<root->right->data;
    if(!root->left) printLevelWise(root->left);
    if(!root->right) printLevelWise(root->right);

}

int main(){

    BinaryTreeNode<int> * root= takeInput();
    printLevelWise(root);
    return 0;
}