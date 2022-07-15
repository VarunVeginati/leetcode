class Solution {
private:
    map<pair<int, vector<int> >, bool> memo;
    
    bool dp(int sum, vector<int> vec) {
        if(sum == 0) {
            return true;
        }
        if(sum < 0 || vec.size()==0) {
            return false;
        }
        
        if(memo.find(make_pair(sum, vec)) != memo.end()) return memo[make_pair(sum, vec)];
        
        memo[make_pair(sum, vec)] = dp(sum-vec[0], {vec.begin()+1, vec.end()}) || 
            dp(sum,{vec.begin()+1, vec.end()});
        
        return memo[make_pair(sum, vec)];
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