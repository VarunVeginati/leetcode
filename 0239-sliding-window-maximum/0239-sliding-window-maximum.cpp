class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        
        for(int i=0; i<k; i++) {
            pq.push(make_pair(nums[i], i));
        }
        
        vector<int> res;
        res.push_back(pq.top().first);
        
        for(int i=k; i<nums.size(); i++) {
            while(!pq.empty() && i-pq.top().second>=k) {
                pq.pop();
            }
            pq.push(make_pair(nums[i], i));
            res.push_back(pq.top().first);
        }
        
        return res;
    }
};