class Solution {
public:
    vector<int> memo;
    
    int dp(int n) {
        if(n==1) return true;
        
        if(memo[n] != -1) return memo[n]==1?true:false;
        
        int a = sqrt(n);
        
        for(int i=1; i<=a; i++) {
            if(!dp(n-(i*i))) {
                memo[n] = 1;
                return true;
            }
        }
        
        memo[n] = 0;
        
        return false;;
    }
    
    bool winnerSquareGame(int n) {
        memo = vector<int>(n+1, -1);
        return dp(n);
    }
};