class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx = INT_MIN;
        
        for(int i=0; i<accounts.size(); i++) {
            int cnt = 0;
            for(int j=0; j<accounts[0].size(); j++) {
                cnt += accounts[i][j];
            }
            mx = max(mx, cnt);
        }
        
        return mx;
    }
};