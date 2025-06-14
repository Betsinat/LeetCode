class MinStack {
private:
    stack<int> mystack;
    stack<int> minstack;

public:
    MinStack() {
    }

    void push(int val) {
        mystack.push(val);
        if(minstack.empty() || val <= minstack.top()){
            minstack.push(val);
        }
    }

    void pop() {
        if(mystack.top() == minstack.top()){
            minstack.pop();
        }
        mystack.pop();
    }

    int top() {
        return mystack.top();
    }

    int getMin() {
        return minstack.top();
    }
};
