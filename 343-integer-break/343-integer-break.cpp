class Solution {
public:
    vector<int> memo;
    
    int dp(int n) {
        if(n==1) return 1;
        
        if(memo[n] != 0) return memo[n];
        
        memo[n] = n;
        
        for(int i=1; i<n; i++) {
            memo[n] = max(memo[n], i*dp(n-i));
        }
        
        return memo[n];
    }
    
    int integerBreak(int n) {
        if(n<=3) return n-1;
        memo = vector<int>(n+1, 0);
        
        return dp(n);
    }
};