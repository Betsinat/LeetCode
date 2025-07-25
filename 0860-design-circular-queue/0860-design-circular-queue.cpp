class MyCircularQueue {
    private:
     vector<int>queue;
     int head;
     int tail;
     int size;
     int capacity;
public:
    MyCircularQueue(int k) {
        queue.resize(k);
        head = 0;
        tail = -1;
        size = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
         tail = (tail+1) % capacity;
         queue[tail] = value;
         size++;
         return true;
        
    }
    bool deQueue() { 
        if(isEmpty())  return false;
        head =(head+1)%capacity;
         size--;
         return true;
    }
    int Front() {
        if(isEmpty()) return -1;
        return queue[head];
    }
    int Rear() {
        if(isEmpty()) return -1;
        return queue[tail];
    }
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */