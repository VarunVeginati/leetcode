class Solution {
public:
    vector<int> memo;
    
    int dp(int n) {
        if(n==1) return 1;
        if(n<1) return 0;
        
        if(memo[n] != 0) return memo[n];
        
        int mn = INT_MAX;
        
        for(int i=1; i*i<=n; i++) {
            mn = min(mn, 1+dp(n-(i*i)));
        }
        
        memo[n] = mn;
        
        return mn;
    }
    
    int numSquares(int n) {
        memo = vector<int>(n+1, 0);
        
        return dp(n);
    }
};