class Solution {
private:
    vector<vector<vector<int>>> memo;
    int M = 1000000007;
    int m1;
    int n1;
    
    long long dp(int i, int j, int N) {
        if(i==m1 || j==n1 || i<0 || j<0) return 1;
        
        if(N==0) return 0;
        
        if(memo[i][j][N] != -1) return memo[i][j][N];
        
        memo[i][j][N] = (dp(i,j-1,N-1)%M + dp(i-1, j, N-1)%M +
                        dp(i,j+1, N-1)%M + dp(i+1, j, N-1)%M)%M;
        
        return memo[i][j][N];
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        m1 = m;
        n1 = n;
        memo = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        
        return dp(startRow, startColumn, maxMove);
    }
};