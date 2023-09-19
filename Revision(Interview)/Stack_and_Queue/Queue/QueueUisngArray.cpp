//  Little Complex, revise it again

#include <iostream>
using namespace std;

class queue{
    int *data;
    int nextIndex; // it will tell the index for enqueue
    int frontIndex; // It will tell the index for dequeue
    int size;
    int capacity;

    public:
    queue(){
        data=new int [4];
        nextIndex=0;
        frontIndex=-1;
        capacity=4;
        size=0;
    }

    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }

    void enqueue(int el){
        if(size==capacity){
            //  means that queue is full and we need to double the size of the queue
            int *newdata=new int[2*capacity];
            int j=0;

            //  firts element is placed at frontIndex
            for(int i=frontIndex;i<capacity;i++){
                newdata[j]=data[i];
                j++;
            }

            for(int i=0;i<frontIndex;i++){
                newdata[j]=data[i];
                j++;
            }

            delete[] data;
            data=newdata;
            frontIndex=0;
            nextIndex=capacity;
            capacity*=2;
        }

        data[nextIndex]=el;
        nextIndex=(nextIndex+1)%capacity;

        //  **** remeber to do this if condition
        if(frontIndex==-1) frontIndex=0;
        size++;
      

    }

    int front(){
        if(size==0) 
        {
            cout<<"queue is empty, top operation not possible"<<endl;
            return 0;
        }
        else {
            return data[frontIndex];
        }
    }

    void  dequeue(){
        if(size==0) 
        {
           
            cout<<"queue is empty, top operation not possible"<<endl;
            return ;
        }
        else {
            int dequeueEl=data[frontIndex];
            frontIndex=(frontIndex+1)%capacity;
            size--;

            //  *** Remember this step
            if(size==0)  
            {
                frontIndex=-1;
                nextIndex=0;

            }

            // *** remeber to do size--
            size--;

            // return dequeueEl;
    }

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