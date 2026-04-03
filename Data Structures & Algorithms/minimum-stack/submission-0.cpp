class MinStack {
private:
    stack<int> min_stack = {};
    stack<int> norm_stack = {};
public:
    MinStack() {
        
    }
    
    void push(int val) {
        norm_stack.push(val);
        min_stack.push(std::min(min_stack.empty() ? val : min_stack.top(), val));

    }
    
    void pop() {
        norm_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return norm_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
