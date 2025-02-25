class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        data.push(val);
        if (min_data.empty() || val <= min_data.top()) {
            min_data.push(val);
        }
    }
    
    void pop() {
        if (data.empty()) return; // Handle empty stack

        if (data.top() == min_data.top()) {
            min_data.pop();
        }
        data.pop();
    }
    
    int top() {
        if (data.empty()) return 0; // Handle empty stack

        return data.top();
    }
    
    int getMin() {
        if (min_data.empty()) return 0; // Handle empty stack

        return min_data.top();
    }
private:
    std::stack<int> data;
    std::stack<int> min_data;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */