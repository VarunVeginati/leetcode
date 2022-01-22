class Solution {
public:
    vector<int> memo;
    vector<int> vec;
    
    int dp(int rem) {
        if(rem == 0) return 1;
        
        if(memo[rem] != -1) return memo[rem];
        
        int res = 0;
        
        for(int num: vec) {
            if(rem-num >= 0)
                res += dp(rem-num);
        }
        
        memo[rem] = res;
        
        return res;
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        memo = vector<int>(target+1, -1);
        vec = nums;
        
        return dp(target);
    }
};