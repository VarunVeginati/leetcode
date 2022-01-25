class MedianFinder {
public:
    int n = 0;
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> q;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        n++;
        if(pq.size() < ((n/2)+1)) {
            if(!q.empty() && q.top()<num) {
                pq.push(q.top());
                q.pop();
                q.push(num);
            } else pq.push(num);
        }
        else{
            if(pq.top()<=num) q.push(num);
            if(pq.top()>num) {
                int a = pq.top();
                if(q.empty()) {
                    q.push(a);
                    pq.pop();
                    pq.push(num);
                }
                else if(q.top()<num) {
                    pq.pop();
                    pq.push(q.top());
                    q.pop();
                    q.push(num);
                    q.push(a);
                } else {
                    pq.pop();
                    pq.push(num);
                    q.push(a);
                }
            }
        }
    }
    
    double findMedian() {
        if(n%2 != 0) return (double) pq.top();
        else {
            double a = pq.top();
            pq.pop();
            double b = pq.top();
            pq.push(a);
            
            return (double) ((a+b)/2);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */