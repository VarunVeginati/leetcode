class Solution {
public:
    int m;
    int n;
    vector<vector<int>> memo;
    
    int dp(int i, int j) {
        if(i>=m || j>=n) return 0;
        if((i==m-2 && j==n-1) || (i==m-1 && j==n-2)) return 1;
        
        if(memo[i][j] != INT_MAX) return memo[i][j];
        
        memo[i][j] = dp(i,j+1) + dp(i+1,j);
        
        return memo[i][j];
    }
    
    int uniquePaths(int p, int q) {
        if(p==1 || q==1) return 1;
        m = p;
        n = q;
        
        memo = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        
        return dp(0,0);
    }
};