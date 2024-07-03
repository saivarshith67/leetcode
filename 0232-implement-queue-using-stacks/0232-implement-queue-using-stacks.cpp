class MyQueue {
public:
    stack<int> st;
    stack<int> st2;
    MyQueue() {
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(st.size() != 1)
        {
            int temp = st.top();
            st.pop();
            st2.push(temp);
        }

        //now stack size is 1
        int ans = st.top();
        st.pop();

        while(!st2.empty())
        {
            int temp = st2.top();
            st2.pop();
            st.push(temp);
        }

        return ans;
    }
    
    int peek() {
        while(st.size() != 1)
        {
            int temp = st.top();
            st.pop();
            st2.push(temp);
        }

        //now stack size is 1
        int ans = st.top();

        while(!st2.empty())
        {
            int temp = st2.top();
            st2.pop();
            st.push(temp);
        }

        return ans;
    }
    
    bool empty() {
        return st.empty();
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