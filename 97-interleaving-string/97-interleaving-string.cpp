class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        if(m+n != s3.length()) return false;
        
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        
        for(int i=0; i<=m; i++) {
            int l = i==0?0:i-1;
            for(int j=0; j<=n; j++) {
                if(i==0 && j==0) continue;
                else if(i==0) {
                    if(s3[l] == s2[j-1])
                        dp[i][j] = dp[i][j-1];
                } else if(j==0) {
                    if(s3[l] == s1[i-1])
                        dp[i][j] = dp[i-1][j];
                } else {
                    if(s3[l] == s1[i-1] && s3[l] == s2[j-1]) {
                        dp[i][j] = dp[i-1][j]==1?1:dp[i][j-1];
                    } else if(s3[l] == s1[i-1]) {
                        dp[i][j] = dp[i-1][j];
                    } else if(s3[l] == s2[j-1]) {
                        dp[i][j] = dp[i][j-1];
                    }
                }
                l++;  
            }
        }
        
        return dp[m][n]==1?true:false;
    }
};