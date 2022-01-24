class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    bool less = false;
    
    KthLargest(int k, vector<int>& nums) {
        if(k>nums.size()) {
            for(int i=0; i<nums.size(); i++)
                pq.push(nums[i]);
            less = true;
        } else {
            for(int i=0; i<k; i++)
                pq.push(nums[i]);
            for(int i=k; i<nums.size(); i++) {
                if(pq.top() < nums[i]) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(less) {
            pq.push(val);
            less = false;
        }
        else if(pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */