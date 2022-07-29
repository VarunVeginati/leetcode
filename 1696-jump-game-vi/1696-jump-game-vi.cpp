class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int,int> > dq;
        dq.push_back(make_pair(nums[0], 0));
        
        int score = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            while(!dq.empty() && dq.front().second<i-k) dq.pop_front();
            
            score = dq.front().first + nums[i];
            
            while(!dq.empty() && dq.back().first<=score) dq.pop_back();
            
            dq.push_back(make_pair(score,i));
        }
        
        return score;
    }
};