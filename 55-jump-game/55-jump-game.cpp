class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> memo(nums.size(), false);
        memo[nums.size()-1] = true;
        int b = nums.size()-1;
        
        for(int i=nums.size()-2; i>=0; i--) {
            int a = i+nums[i];
            int mn = min(a,b);
            for(int j=i+1; j<=mn; j++) {
                if(memo[j]) {
                    memo[i]=true;
                    break;
                }
            }
        }
        
        return memo[0];
    }
};