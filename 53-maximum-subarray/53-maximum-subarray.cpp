class Solution {
public:
    vector<int> vec;
    map<int, int> memo;
    
    int dp(int i) {
        if(i==vec.size()-1) return vec[i];
        
        if(memo.find(i) != memo.end()) return memo[i];
        
        memo[i] = max(vec[i], vec[i]+dp(i+1));;
        
        return memo[i];
    }
    
    int maxSubArray(vector<int>& nums) {
        vec = nums;
        int mx = INT_MIN;
        
        for(int i=0; i<nums.size(); i++) {
            mx = max(mx, dp(i));
        }
        
        return mx;
    }
};