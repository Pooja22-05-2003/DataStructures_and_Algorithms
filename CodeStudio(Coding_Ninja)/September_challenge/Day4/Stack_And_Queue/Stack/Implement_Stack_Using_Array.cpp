//  Question link :https://www.codingninjas.com/studio/problems/stack-implementation-using-array_3210209?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

//  Time complexity -O(1)
//  Space complexity=O(capacity) - [ to create array of capacity size]
// Stack class.
class Stack {
    int size;     // size will the current size of the stack
    int capacity; // capacity will tell the total capacity of the stack
    int nextIndex; // the next index where we can insert the element
    int *data;
public:
    
    Stack(int capacity) {
        // Write your code here.
        size=0;
        this->capacity=capacity;
        nextIndex=0;
        data=new int[capacity];

    }

    void push(int num) {
        // Write your code here.
        if(size==capacity){
            return ;
        }
        data[nextIndex]=num;
        nextIndex++;
        size++;

    }

    int pop() {
        // Write your code here.
        if(size==0) return -1;
        else {
            nextIndex--;
             size--;
            return data[nextIndex];
        }
       
    }
    
    int top() {
        // Write your code here.
        if(size==0) return -1;
        else {
        
            nextIndex--;
            int ans=data[nextIndex];
            nextIndex++;
            
            return ans;
        }
    }
    
    int isEmpty() {
        // Write your code here.
        return (size==0);
    }
    
    int isFull() {
        // Write your code here.
     
        return (size==capacity);
    }
    
};
