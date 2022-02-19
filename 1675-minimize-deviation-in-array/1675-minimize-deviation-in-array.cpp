class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn = INT_MAX;
        
        for(int i=0; i<nums.size(); i++) {
            int a = nums[i]%2==0?nums[i]:nums[i]*2;
            pq.push(a);
            mn = min(a,mn);
        }
        
        int k = nums.size();
        int res = INT_MAX;
        
        while(!pq.empty()) {
            int a = pq.top();
            pq.pop();
            res = min(res, a-mn);
            if(a%2==0) {
                pq.push(a/2);
                mn = min(mn, a/2);
            } else break;
        }
        
        return res;
    }
};