class Solution {
public:
    vector<int> memo;
    
    int dp(int n) {
        if(n<=3) {
            return n;
        }
        
        if(memo[n] != -1) return memo[n];
        
        int ans = INT_MAX;
        int a = sqrt(n);
        
        for(int i=1; i<=a; i++) {
            ans = min(ans, 1+dp(n-(i*i)));
        }
        
        memo[n] = ans;
        
        return ans;
    }
    
    int numSquares(int n) {
        memo = vector<int>(n+1,-1);
        return dp(n);
    }
};