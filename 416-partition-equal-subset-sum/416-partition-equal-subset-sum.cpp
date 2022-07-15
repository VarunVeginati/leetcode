class Solution {
private:
    map<int, bool> memo;
    vector<int> vec;
    
    bool dp(int sum, int i) {
        if(sum == 0) {
            return true;
        }
        if(sum < 0 || i>=vec.size()) {
            return false;
        }
        
        if(memo.find(sum) != memo.end()) return memo[sum];
        
        memo[sum] = dp(sum-vec[i], i+1) || dp(sum,i+1);
        
        return memo[sum];
    }
    
public:
    bool canPartition(vector<int>& nums) {
        vec = nums;
        
        int totalSum = 0;
        
        for(int i=0; i<nums.size(); i++)
            totalSum += nums[i];
        
        if(totalSum%2!=0) return false;
        
        return dp(totalSum/2, 0);
    }
};