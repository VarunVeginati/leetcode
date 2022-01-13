class Solution {
public:
    vector<vector<int>> tri;
    int m;
    vector<vector<int>> memo;
    
    int dp(int r, int c) {
        if(r>=m-1) {
            return tri[r][c];
        }
        
        if(memo[r][c] != INT_MAX) return memo[r][c];
        
        memo[r][c] = tri[r][c] + min(dp(r+1,c), dp(r+1, c+1));
        
        return memo[r][c];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        m = triangle.size();
        tri = triangle;
        memo = vector<vector<int>>(m, vector<int>(m, INT_MAX));
        
        return dp(0,0);
    }
};