#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedList{
    public:
    int data;
    DoublyLinkedList *next;
    DoublyLinkedList*prev;

    DoublyLinkedList(int data)
    {
        this->data=data;
        prev=NULL;
        next=NULL;
    }

    DoublyLinkedList(int data, DoublyLinkedList*next, DoublyLinkedList*prev)
    {
        this->data=data;
        this->next=next;
        this->prev=prev;
    }


};

// TC=O(N)
DoublyLinkedList*  CreateDoublyLinkedList(vector<int>arr)
{
    DoublyLinkedList* head=new DoublyLinkedList(arr[0]);
    DoublyLinkedList* prevnode=head;
    int i=1;

    while(i<arr.size())
    {
        DoublyLinkedList* curr=new DoublyLinkedList(arr[i]);
        prevnode->next=curr;
        curr->prev=prevnode;
        prevnode=curr;
        i++;
    }

    return head;

}

// TC=O(N)
void PrintDLL(DoublyLinkedList* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }

}

//////////////////////////////////////////////
/*

Delete Node in Doubly Linked List
 Node which need to be deleted can be 
0. First Node->head
1. Kth node
2. Last Node->Tail Node

*/
///////////////////////////////////////////

DoublyLinkedList* Deletehead(DoublyLinkedList*head)
{
    // 1->2->3->4
    // prev=will point to head
    // head will one step forward
    // make head->prev=NULL
    // make prev->next and prev->prev=NULL

    DoublyLinkedList*prevnode=head;
    head=head->next;
    head->prev=NULL;
    prevnode->next=NULL;
    prevnode->prev=NULL;
    delete prevnode;
    return head;
    
}


DoublyLinkedList* DeleteTail(DoublyLinkedList*head)
{
    // 1->2->3->4
    // curr=will point to tail
    // prevnode will point to the tail prev
    // make prevnode->next=NULL
    // make curr->next and curr->prev=NULL
    // delete curr and return head

    DoublyLinkedList*curr=head;

    while(curr->next!=NULL) 
    {
        curr=curr->next;
    }
 
    DoublyLinkedList* prevnode=curr->prev;


    prevnode->next=NULL;
    curr->next=NULL;
    curr->prev=NULL;
    delete curr;


    return head;
    
}

DoublyLinkedList* DeleteKthNode(DoublyLinkedList*head,int k)
{
    // 1->2->3->4
    ///1.First reach to the kth node
    // check if the kth node is head, call deletehead function
    //2. Check the kth node is tail, then call the tailDelete function
    //3.then check that the kth node is middle node.
    // for middle node, find the prevnode and the nextnode.
    // point prevnode->next=curr->next;
    // point nextnode->prev=curr->prev
    // make currnode prev and next pointer to the null
    // delete the currnode and return the head
    
    int cnt=0;
    DoublyLinkedList* curr=head;
    while(curr!=NULL && cnt<k)
    {
       
        cnt++;
        if(cnt==k)
        {
            if(curr->prev==NULL)
            {
                // means head node
                return Deletehead(head);
            }
            else if(curr->next==NULL)
            {
                // means the curr node is tail
                return DeleteTail(head); // ***must pass head in the paramter***
            }
            else
            {
                DoublyLinkedList*prevnode=curr->prev;
                DoublyLinkedList*nextnode=curr->next;

                prevnode->next=curr->next;
                nextnode->prev=curr->prev;
                curr->next=NULL;
                curr->prev=NULL;
                delete curr;
                return head;
            }
        }

         curr=curr->next;
    }

    return head;
   
    
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********

    vector<int>arr={2,33,4,1};
    DoublyLinkedList * head= CreateDoublyLinkedList(arr);

    cout<<"Previous Doubly Linked List"<<endl;
    PrintDLL(head);
    cout<<endl;

//////////////////////////////////////////////
/*
//TC=O(N)
// SC=O(1)
Delete Node in Doubly Linked List
 Node which need to be deleted can be 
0. First Node->head
1. Kth node
2. Last Node->Tail Node

*/
///////////////////////////////////////////
    // cout<<"After Deletion of head node,New Doubly Linked List"<<endl;
    // head=Deletehead(head);
    // PrintDLL(head);


    // cout<<"After Deletion of tail node,New Doubly Linked List"<<endl;
    // head=DeleteTail(head);
    // PrintDLL(head);

    cout<<"After Deletion of kth node,New Doubly Linked List"<<endl;
    // head=DeleteKthNode(head,2);
    /*
    // output:
    Previous Doubly Linked List
    2 33 4 1 
    After Deletion of kth node,New Doubly Linked List
    2 4 1 
    */ 

    // head=DeleteKthNode(head,1);
    // PrintDLL(head);
    /*
    // output:
    Previous Doubly Linked List
    2 33 4 1 
    After Deletion of kth node,New Doubly Linked List
    33 4 1 
    */ 

    head=DeleteKthNode(head,4);
    PrintDLL(head);
    /*
   Previous Doubly Linked List
    2 33 4 1 
    After Deletion of kth node,New Doubly Linked List
    2 33 4 
    */ 

   
    return 0;
}

/*
Output:
2 33 4 1
*/