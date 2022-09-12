class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int h_i = n-1;
        int l_i = 0;
        int score = 0;
        int max_score = 0;
        
        while(l_i<=h_i && l_i<n && h_i>=0) {
            if(power<tokens[l_i] && score<=0) {
                return max_score;
            }
            else if(power>=tokens[l_i]) {
                score++;
                power = power-tokens[l_i];
                l_i++;
            } else {
                score--;
                power+=tokens[h_i];
                h_i--;
            }
            
            max_score = max(score, max_score);
        }
        
        return max_score;
    }
};