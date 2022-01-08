class MyQueue {
    stack<int> queue, temp;
public:
    MyQueue() {}
    
    void push(int x) {
        while (!queue.empty()) {
            temp.push(queue.top());
            queue.pop();
        }
        queue.push(x);
        while (!temp.empty()) {
            queue.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int top = peek();
        queue.pop();
        return top;
    }
    
    int peek() {
        return queue.top();
    }
    
    bool empty() {
        return queue.empty();
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
