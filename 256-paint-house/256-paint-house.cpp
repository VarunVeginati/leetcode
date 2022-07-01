class Solution {
private:
    vector<vector<int>> cts;
    vector<vector<int>> memo;
    
public:
    
    int dp(int i, int j) {
        if(i==cts.size()-1) {
            return cts[i][j];
        }
        
        if(memo[i][j] != INT_MAX) return memo[i][j];
        
        int mn = INT_MAX;
        
        for(int k=0; k<3; k++) {
            if(k==j) continue;
            mn = min(mn, cts[i][j] + dp(i+1,k));
        }
        
        memo[i][j] = mn;
        
        return mn;
    }
    
    int minCost(vector<vector<int>>& costs) {
        cts = costs;
        memo = vector<vector<int>>(costs.size(), vector<int>(3, INT_MAX));
        
        int mn = INT_MAX;
        
        for(int i=0; i<3; i++) {
            mn = min(mn, dp(0, i));
        }
        
        return mn;
    }
};