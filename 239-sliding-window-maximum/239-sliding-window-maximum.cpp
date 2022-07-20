class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int> > pq;
        vector<int> res;
        
        for(int i=0; i<k; i++)
            pq.push(make_pair(nums[i], i));
        
        res.push_back(pq.top().first);
        
        for(int i=1; i<=nums.size()-k; i++) {
            pq.push(make_pair(nums[i+k-1], i+k-1));
            
            while(pq.top().second<i || pq.top().second>=i+k) {
                pq.pop();
            }
            
            res.push_back(pq.top().first);
        }
        
        return res;
    }
};