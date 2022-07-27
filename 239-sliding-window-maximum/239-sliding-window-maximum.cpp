class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int> > dq;
        
        for(int i=0; i<k; i++) {
            while(!dq.empty() && dq.back().first<nums[i])
                dq.pop_back();
            
            dq.push_back(make_pair(nums[i], i));
        }
        
        vector<int> res;
        
        res.push_back(dq.front().first);
        
        int left = 1;
        
        for(int i=k; i<nums.size(); i++) {
            while(!dq.empty() && dq.front().second<left) dq.pop_front();
            
            while(!dq.empty() && dq.back().first<nums[i]) dq.pop_back();

            dq.push_back(make_pair(nums[i],i));
            
            res.push_back(dq.front().first);
            left++;
        }
        
        return res;
    }
};