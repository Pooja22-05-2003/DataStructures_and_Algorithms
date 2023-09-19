#include <iostream>
using namespace std;

class Node{
     public:
    int data;
    Node *next;
   
    Node(int el){
        data=el;
        next=NULL;
    }

};

class queue{
    Node *head;
    Node *tail;
    int size;

    public:
    queue(){
        head=NULL;
        tail=NULL;
        size=0;
    }   

    void enqueue(int el){
        Node *newnode=new Node(el);
        if(head==NULL && tail==NULL){
            head=newnode;
            tail=newnode;
        }
        else {
            tail->next=newnode;
            tail=tail->next;
            size++;
        }

    } 

    void dequeue(){
        if(head==NULL && tail==NULL){
            cout<<"queue is Empty, can't dequeue any element"<<endl;
            return ;
        }
        else {
            head=head->next;
            size--;
        }

    }

    int front(){
        if(head==NULL && tail==NULL){
            cout<<"queue is Empty, can't dequeue any element"<<endl;
            return 0;
        }
        else{
            return head->data;
        }
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }
    
};

int main(){

    
    queue q;
    cout<<"queue is empty ? :"<<q.isEmpty()<<endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    cout<<"size of quueue:"<<q.getSize()<<endl;
    cout<<"front:"<<q.front()<<endl;



    q.dequeue();
     cout<<"front:"<<q.front()<<endl;
    cout<<"size of stack:"<<q.getSize()<<endl;
    cout<<"queue is empty ? :"<<q.isEmpty()<<endl;
    return 0;
}