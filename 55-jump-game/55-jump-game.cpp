class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> memo(nums.size(), false);
        memo[nums.size()-1] = true;
        
        for(int i=nums.size()-2; i>=0; i--) {
            for(int j=i+1; j<=i+nums[i]; j++) {
                if(memo[j]) {
                    memo[i]=true;
                    break;
                }
            }
        }
        
        return memo[0];
    }
};