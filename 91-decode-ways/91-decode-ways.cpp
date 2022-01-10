class Solution {
public:
    map<int,int> memo;
    
    int dp(int i, string s) {
        if(memo.find(i) != memo.end()) return memo[i];
        if(i==s.length()) return 1;
        
        if(s[i]=='0') return 0;
        
        if(i==s.length()-1) return 1;
        
        int ans = dp(i+1, s);
        if(stoi(s.substr(i,2)) <= 26)
            ans+= dp(i+2,s);
        
        memo[i] = ans;
        
        return ans;
    }
    
    int numDecodings(string s) {
        return dp(0, s);
    }
};