#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val)
    {
        data=val;
        next=nullptr;
        prev=nullptr;
    }
     Node(int val,Node *prev1,Node*next1)
    {
        data=val;
        next=next1;
        prev=prev1;
    }


};

Node* constructDLL(vector<int> arr) {
    // Write your code here
    Node * head=NULL;
    Node *prevNode=NULL;

    for (int i = 0; i < arr.size(); i++) {
       
      Node *newNode = new Node(arr[i],prevNode,nullptr);
       if(prevNode==NULL ){
           head=newNode;
       } else {
           prevNode->next = newNode;
        //    newNode->prev = prevNode;
       }
       prevNode=newNode;
      

    }
    return head;
}

void printDLL(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}

int main()
{
    vector<int>arr={4,3,7,5};
    Node * head=constructDLL(arr);
    printDLL(head);
    return 0;
}

/*
Output : 4->3->7->5->
*/