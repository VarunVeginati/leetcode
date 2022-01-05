class Solution {
public:
    vector<int> vec;
    vector<int> memo;
    
    int dp(int i) {
        if(i>=vec.size()-1) {
            return 0;
        }
        
        if(memo[i] != 0) return memo[i];
        
        int mn = INT_MAX;
        
        for(int j=vec[i]; j>=1; j--) {
            mn = min(mn, dp(i+j));
        }
        
        memo[i] = mn == INT_MAX ? INT_MAX:1+mn;
        
        return memo[i];
    }
    
    int jump(vector<int>& nums) {
        vec = nums;
        vector<int> vec(nums.size()-1, 0);
        memo = vec;
        
        return dp(0);
    }
};