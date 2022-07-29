class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int,int> > dq;
        dq.push_back(make_pair(nums[n-1], n-1));
        
        int a = nums[n-1];
        
        for(int i=n-2; i>=0; i--) {
            while(!dq.empty() && dq.front().second>i+k) dq.pop_front();
            
            a = nums[i]+dq.front().first;
            
            while(!dq.empty() && dq.back().first<=a) dq.pop_back();
            
            dq.push_back(make_pair(a,i));
        }
        
        return a;
    }
};