class Solution {
public:
//     vector<int> memo;
//     vector<int> cns;
    
//     int dp(int amount) {
//         if(amount==0) return 0;
//         if(amount<0) return -1;
        
//         if(memo[amount] != INT_MAX) return memo[amount];
        
//         int min = INT_MAX;
        
//         for(int i=cns.size()-1; i>=0; i--) {
//             int res = dp(amount-cns[i]);
//             if(res != -1 && res<min)
//                 min=1+res;
//         }
        
//         memo[amount] = min == INT_MAX ? -1:min;
        
//         return memo[amount];
//     }
    
    int coinChange(vector<int>& coins, int amount) {
//         memo = vector<int>(amount+1, INT_MAX);
//         cns = coins;
        
//         return dp(amount);
        
        vector<int> memo(amount+1, INT_MAX);
        memo[0] = 0;
        
        for(int i=1; i<=amount; i++) {
            for(int j=0; j<coins.size(); j++) {
                if(i-coins[j] >= 0 && memo[i-coins[j]] != INT_MAX) {
                    memo[i] = min(memo[i], 1+memo[i-coins[j]]);
                }
            }
        }
        
        return memo[amount] == INT_MAX ? -1: memo[amount];
    }
};