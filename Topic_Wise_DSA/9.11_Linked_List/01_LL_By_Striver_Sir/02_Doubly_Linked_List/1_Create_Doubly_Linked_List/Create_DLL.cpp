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
    DoublyLinkedList* prev=head;
    int i=1;

    while(i<arr.size())
    {
        DoublyLinkedList* curr=new DoublyLinkedList(arr[i]);
        prev->next=curr;
        prev=curr;
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
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********

    vector<int>arr={2,33,4,1};
    DoublyLinkedList * head= CreateDoublyLinkedList(arr);

    PrintDLL(head);
   
    return 0;
}

/*
Output:
2 33 4 1
*/