// TC(Push)=O(n)-Pushing 1 element takes O(n) time
// TC=(Pop)=O(1)
// SC=O(1)
class MyQueue {
public:
   stack<int>s1,s2; 
    MyQueue() {
    
    }
    
    void push(int x) {
        // we will store the stack1 element just like queue, means that the element which comes first will at the top of the stack.

        // s1 is the original which we will use as queue and s2 is the helper stack
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

    }
    
    int pop() {
        int ans=s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */