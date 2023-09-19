//  Easy as comapre to QueueUsingArray
#include <iostream>
using namespace std;

class stakUsingArray{
    int *data;
    int nextIndex;
    int capacity;

     public:
    stakUsingArray(){
        data=new int[4];
        nextIndex=0;
        capacity=4;
    }
   

    /*5 functions : 1. size ;  2. isEmpty ; 3. push ; 4. pop ; 5. top */

    int size(){

        // *** here u not beed to return nextIndex+1, because nextIndex is already 1 index ahead.
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex==0;
    }

    void push(int el){
        if(nextIndex==capacity){
            //  means array is full and we need to double it
            int *newdata=new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newdata[i]=data[i];
            }
            delete[] data;
            data=newdata;
            capacity*=2;
        }
        data[nextIndex]=el;
        nextIndex++;
    }

    void pop()
    {
        if(nextIndex==0){
            cout<<"stack is already empty, can't pop elements"<<endl;
            return ;
        }
        else nextIndex--;
    }

    int top(){
        if(nextIndex==0){
            cout<<"stack is already empty, not have any top elements"<<endl;
            return 0;
        }
        else return data[nextIndex-1];
    }

};

int main(){

    stakUsingArray s;
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