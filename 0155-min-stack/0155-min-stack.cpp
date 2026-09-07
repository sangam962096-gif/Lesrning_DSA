class MinStack {
    stack<long long> st;
    long long min_val;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        long long v = val;
        if (st.empty()) {
            min_val = v;
            st.push(v);
        } else {
            if (v < min_val) {
                st.push(2 * v - min_val);
                min_val = v;
            } else {
                st.push(v);
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        long long x = st.top();
        st.pop();
        if (x < min_val) {
            min_val = 2 * min_val - x;
        }
    }
    
    int top() {
        long long x = st.top();
        if (x < min_val) {
            return min_val;
        }
        return x;
    }
    
    int getMin() {
        return min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */