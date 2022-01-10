class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length()) return addBinary(b,a);
        
        int a_l = a.length();
        int b_l = b.length();
        int carry = 0;
        string res = "";
        
        for(int i=0; i<a_l; i++) {
            char ac = a[a_l-i-1];
            char bc = b_l-i-1>=0 ? b[b_l-i-1]:'0';
            
            if(ac=='0' && bc=='0' && carry==0) {
                res += '0';
                carry=0;
            } else if(ac=='0' && bc=='0' && carry==1) {
                res += '1';
                carry=0;
            } else if(ac=='0' && bc=='1' && carry==0) {
                res += '1';
                carry=0;
            } else if(ac=='0' && bc=='1' && carry==1) {
                res += '0';
                carry=1;
            } else if(ac=='1' && bc=='0' && carry==0) {
                res += '1';
                carry=0;
            } else if(ac=='1' && bc=='0' && carry==1) {
                res += '0';
                carry=1;
            } else if(ac=='1' && bc=='1' && carry==0) {
                res += '0';
                carry=1;
            } else {
                res += '1';
                carry=1;
            }
        }
        
        if(carry == 1) res+='1';
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};