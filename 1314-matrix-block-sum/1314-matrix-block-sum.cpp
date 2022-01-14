class Solution {
public:
    vector<vector<int>> dp;
    
    int sum_range(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row1][col2+1] - dp[row2+1][col1] + dp[row1][col1];
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        dp = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] + mat[i][j] - dp[i][j];
            }
        }
        
        vector<vector<int>> res = vector<vector<int>>(m, vector<int>(n));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int row1 = i-k<0?0:i-k;
                int col1 = j-k<0?0:j-k;
                int row2 = i+k>=m?m-1:i+k;
                int col2 = j+k>=n?n-1:j+k;
                res[i][j] = sum_range(row1, col1, row2, col2);
            }
        }
        
        return res;
    }
};