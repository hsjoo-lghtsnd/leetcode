class MyQueue {
    stack<int> main, out;
private:
    void reset_stack() {
        if (out.empty()) {
            while (!main.empty()) {
                out.push(main.top());
                main.pop();
            }
        }
        return;
    }
public:
    MyQueue() {

    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        reset_stack();
        int temp = out.top();
        out.pop();
        return temp;
    }
    
    int peek() {
        reset_stack();
        return out.top();
    }
    
    bool empty() {
        return main.empty() && out.empty();
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
