class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        double num = log(n);
        double den = log(4);
        
        string s = to_string(num/den);
        bool flag = false;
        
        for(int i=0; i<s.length(); i++) {
            if(flag && (int)s[i]-48 > 0) return false;
            else if(!flag && s[i]=='.') flag = true;
        }
        
        return true;
    }
};