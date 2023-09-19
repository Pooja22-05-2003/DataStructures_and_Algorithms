//  Little complex as comapre to queueUsingLL
#include <iostream>
using namespace std;


class Node{
    public:

    int data;
    Node *next;

    Node(int data){
        this->data=data;
        next=NULL;  
    }

};

class stackUisngLL{
    Node *head;
     int si;

    public:
    
    stackUisngLL(){
        head=NULL;
        si=0;
    }
    void push(int el){
        Node *newNode=new Node(el);
        if(head==NULL){
            head=newNode;
        }
        else {
            newNode->next=head;
            head=newNode;
        }
        si++;
    }

    void pop(){
        if(head==NULL){
            cout<<"stack is empty, pop can't occur"<<endl;
            return ;
        }
        else{
            head=head->next;
        }
        si--;
    }

    int top(){
         if(head==NULL){
            cout<<"stack is empty, top can't occur"<<endl;
            return 0;
        }
        else{
            return head->data;
        }
    }

    bool isEmpty(){
        return head==NULL;
    }

    int size(){
        return this->si;
    }
};

int main(){

    stackUisngLL s;
     cout<<"stack is empty ? :"<<s.isEmpty()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    cout<<"size of stack:"<<s.size()<<endl;
    cout<<"top:"<<s.top()<<endl;



    s.pop();
    cout<<"size of stack:"<<s.size()<<endl;
    cout<<"stack is empty ? :"<<s.isEmpty()<<endl;

    return 0;
}