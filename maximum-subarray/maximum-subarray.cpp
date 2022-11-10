class Solution {
public:
    vector<int> memo;
    
    int dp(int i, vector<int>& nums) {
        if(i==nums.size()-1) {
            memo[i] = nums.back();
            return nums.back();
        }
        
        if(memo[i] != -1) return memo[i];
        
        memo[i] = max(nums[i], nums[i]+dp(i+1, nums));
        
        return memo[i];
    }
    
    int maxSubArray(vector<int>& nums) {
        memo = vector<int>(nums.size(),-1);
        
        dp(0, nums);
        
        int ans = nums[0];
        
        for(int i=0; i<memo.size(); i++)
            ans = max(ans, memo[i]);
        
        return ans;
    }
};