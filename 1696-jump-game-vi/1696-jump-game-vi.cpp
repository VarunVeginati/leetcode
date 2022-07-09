class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        int n = nums.size();
        vector<int> dp(n, 0);
        
        dp[n-1] = nums.back();
        dp[n-2] = nums[n-2]+dp[n-1];
        
        priority_queue<pair<int,int>> pq;
        pq.push(make_pair(dp[n-1], n-1));
        pq.push(make_pair(dp[n-2], n-2));
        
        for(int i=n-3; i>=0; i--) {
            int a = min(i+k, n-1);
            while(pq.top().second > a) {
                pq.pop();
            }
            dp[i] = nums[i]+pq.top().first;
            pq.push(make_pair(dp[i], i));
        }
        
        return dp[0];
    }
};