class Solution {
private:
    set<string> wordsSet;
    map<string,int> memo;
    
public:
    
    int dp(string s) {
        if(s.length()==1) return 1;
        
        if(memo.find(s) != memo.end()) return memo[s];
        
        int mx=1;
        for(int j=0; j<s.length(); j++) {
            string subString = s.substr(0,j) + s.substr(j+1);
            if(wordsSet.find(subString) != wordsSet.end()) {
                mx = max(mx, 1+dp(subString));
            }
        }
        
        memo[s] = mx;
        
        return memo[s];
    }
    
    int longestStrChain(vector<string>& words) {
        for(int i=0; i<words.size(); i++)
            wordsSet.insert(words[i]);
        
        int mx = 0;
        
        for(int i=0; i<words.size(); i++) {
            mx = max(mx, dp(words[i]));
        }
        
        return mx;
    }
};