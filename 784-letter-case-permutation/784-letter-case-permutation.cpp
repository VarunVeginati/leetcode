class Solution {
public:
    vector<string> res;
    
    void bt(int i, string str, string s) {
        if(str.length()==s.length()) {
            res.push_back(str);
            return;
        } else if(i>=s.length()) return;
        
        if((int)s[i] >=48 && (int)s[i]<=57) {
            bt(i+1, str+s[i], s);
        } else {
            bt(i+1,str+ (char) tolower(s[i]), s);
            bt(i+1,str+ (char) toupper(s[i]), s);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        bt(0, "", s);
        return res;
    }
};