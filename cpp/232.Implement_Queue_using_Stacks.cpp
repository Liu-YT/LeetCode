class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s.size() == 0)   first = x;
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> tmp;
        while(!s.empty()) {
            tmp.push(s.top());
            s.pop();
        }
        int ans = tmp.top();
        tmp.pop();
        if(!tmp.empty())    first = tmp.top();
        while(!tmp.empty()) {
            s.push(tmp.top());
            tmp.pop();
        }
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        return first;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }

private:
    stack<int> s;
    int first;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */