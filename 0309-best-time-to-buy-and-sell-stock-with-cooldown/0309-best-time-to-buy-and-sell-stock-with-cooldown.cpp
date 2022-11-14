class Solution {
public:
    vector<int> memo;
    
    int dp(int i, vector<int>& prices) {
        if(i>=prices.size()-1) return 0;
        
        if(memo[i] != -1) return memo[i];
        
        int ans = 0;
        
        for(int j=i+1; j<prices.size(); j++) {
            int a = prices[j]-prices[i]+dp(j+2, prices);
            ans = max(ans, a);
        }
        
        memo[i] = max(ans, dp(i+1, prices));
        
        return memo[i];
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memo = vector<int>(n, -1);
        
        return dp(0, prices);
    }
};