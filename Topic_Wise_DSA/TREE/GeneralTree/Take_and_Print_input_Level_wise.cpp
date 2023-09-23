#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T Data;
    vector<TreeNode<T>*> children;

  
    TreeNode(T data){
        Data=data;
      
    }

};

TreeNode<int>*  takeInputLevelWise(){
    int rootVal;
    cout<<"Enter root Data:"<<endl;
    cin>>rootVal;
    TreeNode <int> *root=new TreeNode <int>(rootVal);
    queue<TreeNode<int>*>q;
    q.push(root);
    

    while(!q.empty()){
        TreeNode <int> * cur=q.front();
        q.pop();

        int n;
        cout<<"Enter number of children of Node "<<cur->Data<<" : "<<endl;
        cin>>n;

        for(int i=0;i<n;i++){
            int childData;
            cout<<"Enter "<<i<<" th child of Node "<<cur->Data<<" :"<<endl;
            cin>>childData;
            TreeNode<int>*child=new TreeNode<int>(childData);
            cur->children.push_back(child);
            q.push(child);

        }


    }

    return root;

}


void PrintLevelWise(TreeNode <int> *root){
    queue<TreeNode<int>*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int> *curr=q.front();
        q.pop();
        cout<<curr->Data<<":";
        for(int i=0;i<curr->children.size();i++){
            cout<<curr->children[i]->Data<<" ";
        }
        cout<<endl;
        for(int i=0;i<curr->children.size();i++){
            q.push(curr->children[i]);
        }

    }
}




int main(){
    TreeNode<int> * root=takeInputLevelWise();
    PrintLevelWise(root);

}