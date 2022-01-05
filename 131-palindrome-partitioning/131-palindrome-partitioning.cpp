class Solution {
public:
    vector<vector<string>> res;
    
    bool is_palindrome(string s) {
        string str = s;
        reverse(s.begin(), s.end());
        return s == str;
    }
    
    void back_track(string s, vector<string> vec, int start) {
        if(start >= s.length()) {
            res.push_back(vec);
            return;
        }
        
        for(int end=start; end<s.length(); end++) {
            string str = s.substr(start, end-start+1);
            if(is_palindrome(str)) {
                vec.push_back(str);
                back_track(s,vec, end+1);
                vec.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        back_track(s, vec, 0);
        return res;
    }
};