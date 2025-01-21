class MinStack {
public:
    stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        int mini=INT_MAX;
        stack<int>st1;
        while(!st.empty())
        {
            int a=st.top();
            st.pop();
            mini=min(mini,a);
            st1.push(a);
        }
        while(!st1.empty())
         {
            st.push(st1.top());
            st1.pop();
         }
         return mini;
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