class Solution {
public:
    vector<int> numbers;
    map<int,int> memo;
    
    int dp(int i) {
        if(i==0) return numbers[i];
        if(i==1) return max(numbers[i], numbers[i-1]);
        
        if(memo.find(i) == memo.end())
            memo[i] = max(numbers[i]+dp(i-2), dp(i-1));
        
        return memo[i];
    }
    
    int rob(vector<int>& nums) {
        numbers = nums;
        
        return dp(nums.size()-1);
    }
};