class Solution {
public:
    vector<int> memo;
    int n;
    vector<int> prices;
    
    int dp(int i) {
        if(i>=n-1) return 0;
        
        if(memo[i] == 0) {
            int mx = 0;
        
            for(int j=i+1; j<n; j++) {
                int a = prices[j]-prices[i]+dp(j+2);
                mx = max(mx, a);
            }

            memo[i] = max(mx, dp(i+1));
        }
        
        return memo[i];
    }
    
    int maxProfit(vector<int>& pcs) {
        n = pcs.size();
        prices = pcs;
        if(n==1) return 0;
        
        memo = vector<int>(n, 0);
        
        return dp(0);
    }
};