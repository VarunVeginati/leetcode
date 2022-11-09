class Solution {
public:
    int clamp(long ans) {
        if(ans<INT_MIN) return INT_MIN;
        if(ans>INT_MAX) return INT_MAX;
        
        return ans;
    }
    
    int myAtoi(string s) {
        long ans = 0;
        bool negative = false;
        bool started = false;
        
        for(char c: s) {
            if(!started && (c-'-'==0 || c-'+'==0)) {
                started = true;
                if(c-'-'==0) negative = true;
            } else if(c-'0'>=0 && c-'0'<=9) {
                started = true;
                ans = ans*10 + (c-'0');
                if(ans>INT_MAX) ans = INT_MAX+(long)10;
            } else if(c-' '==0 && !started) continue;
            else {
                ans = negative ? -1*ans:ans;
                return clamp(ans);
            }
        }
        
        ans = negative ? -1*ans:ans;
        return clamp(ans);
    }
};