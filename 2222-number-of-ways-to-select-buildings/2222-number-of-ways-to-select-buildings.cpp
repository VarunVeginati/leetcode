class Solution {
public:
    long long numberOfWays(string s) {
        long long ans = 0;
        int total_1s = 0;
        int total_0s = 0;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='0') total_0s++;
            else total_1s++;
        }
        
        int left_0s = 0;
        int left_1s = 0;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='0') {
                ans += (left_1s*(total_1s-left_1s));
                left_0s++;
            } else {
                ans += (left_0s*(total_0s-left_0s));
                left_1s++;
            }
        }
        
        return ans;
    }
};