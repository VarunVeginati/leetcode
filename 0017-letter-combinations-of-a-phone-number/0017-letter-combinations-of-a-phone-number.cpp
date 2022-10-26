class Solution {
public:
    vector<string> res;
    int n;
    map<char,string> m;
    
    void bt(string s, string &digits, int start) {
        if(s.length()==n) {
            res.push_back(s);
            return;
        }
        
        for(int i=start; i<digits.length(); i++) {
            for(int j=0; j<m[digits[i]].length(); j++) {
                bt(s+m[digits[i]][j], digits, i+1);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        n = digits.length();
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        if(n==0) return res;
        
        bt("", digits, 0);
        
        return res;
    }
};