class MyQueue {
private:
    stack<int> isk;  // input stack
    stack<int> osk;  // output stack

public:
    MyQueue() {
        // constructor
    }

    void push(int x) {
        isk.push(x);
    }

    int pop() {
        if (osk.empty()) {
            while (!isk.empty()) {
                osk.push(isk.top());
                isk.pop();
            }
        }
        int front = osk.top();
        osk.pop();  
        return front;
    }

    int peek() {
        if (osk.empty()) {
            while (!isk.empty()) {
                osk.push(isk.top());
                isk.pop();
            }
        }
        return osk.top();
    }

    bool empty() {
        return isk.empty() && osk.empty();
    }
};
