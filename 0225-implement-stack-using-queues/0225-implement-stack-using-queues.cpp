class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
      q.push(x);
      for(int i=1;i<q.size();i++)
      {
            int a=q.front();
            q.pop();
            q.push(a);
      }
    }
    
    int pop() {
        int a=q.front();
        q.pop();
        return a;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty()==true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */