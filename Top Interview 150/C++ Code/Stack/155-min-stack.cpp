class MinStack {
public:
    stack<int>s1,s2;
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.empty()) s2.push(val);
        else s2.push(min(s2.top(),val));
    }
    
    void pop() {
        s1.pop(),s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
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


class MinStack2 {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>>st;
    int mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
            mini=val;
        else mini=min(val,st.top().second);
        st.push({val,mini});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
       return  st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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
