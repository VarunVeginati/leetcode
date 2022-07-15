class Solution {
private:
    map<int, bool> memo;
    
    bool dp(int sum, vector<int> vec) {
        if(sum == 0) {
            return true;
        }
        if(sum < 0 || vec.size()==0) {
            return false;
        }
        
        if(memo.find(sum) != memo.end()) return memo[sum];
        
        memo[sum] = dp(sum-vec[0], {vec.begin()+1, vec.end()}) || 
            dp(sum,{vec.begin()+1, vec.end()});
        
        return memo[sum];
    }
    
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int totalSum = 0;
        
        for(int i=0; i<nums.size(); i++)
            totalSum += nums[i];
        
        if(totalSum%2!=0) return false;
        
        return dp(totalSum/2, nums);
    }
};