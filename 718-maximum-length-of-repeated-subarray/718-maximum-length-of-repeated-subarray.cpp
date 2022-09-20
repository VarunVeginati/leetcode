class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int mx = 0;
        
        for(int i=0; i<m; i++) {
            dp[0][i] = nums1[i]==nums2[0] ? 1 : 0;
            mx = max(mx, dp[0][i]);
        }
        
        for(int i=0; i<n; i++) {
            dp[i][0] = nums2[i]==nums1[0] ? 1 : 0;
            mx = max(mx, dp[i][0]);
        }
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(nums1[j]==nums2[i]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                    mx = max(mx, dp[i][j]);
                }
            }
        }
        
        return mx;
    }
};