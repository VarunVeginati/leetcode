class Solution {
public:
    vector<vector<string>> chars;
    int n_c = 4;
    int n_r;
    
    void back_track(int row, vector<string>& vec, string s) {
        if(s.length() == n_r) {
            vec.push_back(s);
            return;
        }
        for(int col=0; col<n_c; col++) {
            if(chars[row][col] == "")
                continue;
            else {
                back_track(row+1, vec, s+chars[row][col]);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        vector<string> vec;
        if(digits == "") return vec;
        n_r = digits.size();
        
        vector<vector<string>> v(n_r, vector<string> (n_c, ""));
        
        chars = v;
        
        for(int i=0; i<n_r; i++) {
            for(int j=0; j<m[digits[i]].size(); j++) {
                chars[i][j] = m[digits[i]][j];
            }
        }
        
        back_track(0, vec, "");
        
        return vec;
    }
};