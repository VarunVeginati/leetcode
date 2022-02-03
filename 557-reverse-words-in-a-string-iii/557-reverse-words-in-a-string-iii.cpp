class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string tmp = "";
        
        for(int i=0; i<s.length(); i++) {
            if(s[i]==' ') {
                reverse(tmp.begin(), tmp.end());
                res += tmp;
                res += s[i];
                tmp = "";
            } else {
                tmp+=s[i];
            }
        }
        reverse(tmp.begin(), tmp.end());
        res += tmp;
        return res;
    }
};