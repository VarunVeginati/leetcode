class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(word1[i]==word2[j]) {
                    dp[i][j] = 1+dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        
        return word1.length()+word2.length() - (2*dp[0][0]);
    }
};