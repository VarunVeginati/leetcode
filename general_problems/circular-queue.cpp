class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
    
public:
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        else {
            if(isEmpty()) head++;
            tail = (tail+1)%size;
            data[tail] = value;
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        else {
            if(head == tail) {
                head = -1;
                tail = -1;
            } else {
                head = (head+1)%size;
            }
            return true;
        }
    }
    
    int Front() {
        if(head == -1) return -1;
        return data[head];
    }
    
    int Rear() {
        if(head == -1) return -1;
        return data[tail];
    }
    
    bool isEmpty() {
        return head == -1 && tail == -1;
    }
    
    bool isFull() {
        return ((tail + 1) % size) == head;
    }
};