#include <iostream>
#include <queue>
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
    cout<<"Enter root  data:"<<endl;
    cin>>rootData;

    if(rootData==-1) return NULL;
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while(!q.empty()){
        BinaryTreeNode<int>*cur=q.front();
        q.pop();
        int leftData;
        cout<<"Enter left child data of Node "<<cur->data<<": ";
        cin>>leftData;
        if(leftData!=-1) {
            BinaryTreeNode<int> *leftChild=new BinaryTreeNode<int>(leftData);
            cur->left=leftChild;
            q.push(leftChild);
        }

        int rightData;
        cout<<"Enter right child data of Node "<<cur->data<<": ";
        cin>>rightData;
        if(rightData!=-1) {
            BinaryTreeNode<int> *rightChild=new BinaryTreeNode<int>(rightData);
            cur->right=rightChild;
            q.push(rightChild);
        }

    }
    return root;

}



void printLevelWise(BinaryTreeNode<int>*root){
    if(root==NULL) return;
    
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while(!q.empty()){
        BinaryTreeNode<int>*cur=q.front();
        q.pop();
        cout<<cur->data<<":";

        if(cur->left) 
        {
            cout<<"L:"<<cur->left->data<<" ";
            q.push(cur->left);
        }
        if(cur->right) 
        {
            cout<<"R:"<<cur->right->data<<" "<<endl;
            q.push(cur->right);
        }
       

    }

}

int main(){

    BinaryTreeNode<int> * root= takeInput();
    printLevelWise(root);
    return 0;
}