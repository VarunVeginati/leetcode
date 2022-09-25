class MyCircularQueue {
private:
    int len;
    vector<int> vec;
    int i = 0;
    int j= -1;
    
public:
    MyCircularQueue(int k) {
        len = k;
        vec = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        
        j = (j+1)%len;
        vec[j] = value;
        
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        
        if(i%len==j%len) {
            i=0; j=-1;
            return true;
        }
        i= (i+1)%len;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        
        return vec[i%len];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        
        return vec[j%len];
    }
    
    bool isEmpty() {
        return j==-1;
    }
    
    bool isFull() {
        if(j==-1) return false;
        if(i>j) return i-j==1;
        
        return j-i+1==len;
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