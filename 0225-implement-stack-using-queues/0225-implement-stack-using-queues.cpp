#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;  

public:
    MyStack() {
       
    }

    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 1; i < size; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (!q.empty()) {
            int val = q.front();
            q.pop();
            return val;  
        }
        return -1; 
    }

    int top() {
        if (!q.empty()) {
            return q.front();
        }
        return -1;
    }

    bool empty() {
        return q.empty();
    }
};
