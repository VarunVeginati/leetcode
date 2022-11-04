class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN) return 0;
        if(x<0) return -1*reverse(x*-1);
        string s = to_string(x);
        long ans = 0;
        
        for(int i=s.length()-1; i>=0; i--) {
            ans  = ans*10 + (s[i]-'0');
            if(ans > INT_MAX) return 0;
        }
        
        return ans;
    }
};