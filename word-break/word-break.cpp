class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, int> hashmap;
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        
        for(int i=0;i<wordDict.size();i++) {
            hashmap[wordDict[i]]++;
        }
        
        for(int i=1; i<=s.length(); i++) {
            for(int j=0; j<i; j++) {
                if(dp[j] && hashmap[s.substr(j, i-j)] > 0) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
};