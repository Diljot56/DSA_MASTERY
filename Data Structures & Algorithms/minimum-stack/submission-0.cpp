class MinStack {
public:
    stack<int> s;
    stack<int> minst;
    MinStack() {

    }
    
    void push(int val) {
        if(minst.empty() || val <= minst.top()){
            minst.push(val);
        }
        s.push(val);
    }
    
    void pop() {
        if(minst.top() == s.top()){
            minst.pop();
        }
        s.pop();
    }
    
    int top() {
        if(!s.empty()){
            return s.top();
        }
        return -1;
    }
    
    int getMin() {
        if(!minst.empty()){
            return minst.top();
        }
        return -1;
    }
};
