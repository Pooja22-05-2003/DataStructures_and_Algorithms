#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;

    Node(int data1)
    {
        data=data1;
        next=NULL;
    }
    Node(int data1, Node * next1)
    {
        data=data1;
        next=next1;
    }

};


void printLL(Node * head)
{
    Node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
int main()
{
    vector<int>arr={2,4,55,6};
    Node *head=NULL;
    Node *prev=NULL;
    for(int i=0;i<arr.size();i++)
    {
        Node * newNode=new Node(arr[i]);
        
        // if it is the first node
        if(prev==NULL)
        {
            head=newNode;
            
        }

        else 
        {
            prev->next=newNode;
        }
        prev=newNode;
    }

    printLL(head);
    return 0;
}

/*
Output : 
2->4->55->6->
*/