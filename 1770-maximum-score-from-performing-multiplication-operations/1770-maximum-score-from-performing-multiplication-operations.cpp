class Solution {
public:
    vector<vector<int>> memo;
    
    int dp(vector<int> &nums, vector<int> &multipliers, int i, int left) {
        if(i>=multipliers.size()) return 0;
        
        int right = nums.size()-1-(i-left);
        
        if(memo[i][left] != INT_MAX) return memo[i][left];
        
        memo[i][left] = max((multipliers[i]*nums[left])+dp(nums, multipliers, i+1,left+1), (multipliers[i]*nums[right]) + dp(nums, multipliers, i+1,left));
        
        return memo[i][left];
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        memo = vector<vector<int>>(multipliers.size(), vector<int>(multipliers.size(), INT_MAX));
        
        return dp(nums,multipliers, 0, 0);
    }
};