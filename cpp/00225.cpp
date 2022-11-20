class MyStack {
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        for (int i = 0; i != q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int front = top();
        q.pop();
        return front;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

