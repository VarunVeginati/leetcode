class Solution {
public:
    vector<vector<int>> memo;
    string s;
    
    int dp(int left, int right) {
        int len = 0;
        if(left==right) return 1;
        
        if(left>right) return 0;
        
        if(memo[left][right] != -1) {
            return memo[left][right];
        }
        else if(s[left] == s[right]) {
            len = 2+dp(left+1, right-1);
        } else {
            len = max(len, max(dp(left+1, right), dp(left, right-1)));
        }
        
        memo[left][right] = len;
        
        return len;
    }
    
    int longestPalindromeSubseq(string str) {
        s = str;
        int n = s.length();
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        
        return dp(0, n-1);
    }
};