#include <iostream>
#include <queue>
using namespace std;

class Node
{
   public:
   int data;
   Node* left;
   Node* right;
   
   Node(int data)
   {
       this->data=data;
       left=NULL;
       right=NULL;
   }
   
};


Node* InsertNode(Node* root, int data)
{
    // base case, if root even not exist of the binary tree
    if(root==NULL)
    {
        Node* newnode=new Node(data);
        return newnode;
    }
    
    if(data>root->data) 
    {
        // Insert the node in the root right
        root->right=InsertNode(root->right,data);
    }
    
    if(data<root->data)
    {
        // Insert the node in the root left
        root->left=InsertNode(root->left,data); 
    }
    
    return root;
}
Node* takeInput(Node* root)
{
    int data;
    cin>>data;
    
   
    while(data!=-1)
    {      
        root=InsertNode(root,data);
        cin>>data;
    }
    return root;
}

void printLevelWise(Node*root){
    if(root==NULL) return;
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node*cur=q.front();
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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
    cout<<"Enter the Nodes of the BST :"<<endl;
    Node* root=NULL;
    root=takeInput(root);
    
    cout<<"Printing the BST Node Level wise:"<<endl;
    printLevelWise(root);
    
    return 0;
}