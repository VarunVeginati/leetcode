class Solution {
public:
    int row;
    int col;
    vector<vector<int>> mat;
    vector<int> directions = {-1,0,1};
    vector<vector<int>> memo;
    
    int dp(int r, int c) {
        if(r>=row-1) {
            return mat[r][c];
        }
        
        if(memo[r][c]!=INT_MAX) return memo[r][c];
        
        int mn = INT_MAX;
        
        for(int dir: directions) {
            if(c+dir<0 || c+dir>=col)
                continue;
            mn = min(mn, mat[r][c] + dp(r+1, c+dir));
        }
        
        memo[r][c] = mn;
        
        return memo[r][c];
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        mat = matrix;
        row = matrix.size();
        col = matrix[0].size();
        memo = vector<vector<int>>(row, vector<int>(col, INT_MAX));
        
        int mn = INT_MAX;
        
        for(int i=0; i<col; i++) {
            mn = min(mn, dp(0, i));
        }
        
        return mn;
    }
};