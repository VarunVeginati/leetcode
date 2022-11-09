class Solution {
public:
    vector<string> res;
    
    void bt(string ans, int a, int b, int n) {
        if(ans.length() == 2*n) {
            res.push_back(ans);
            return;
        }
        
        if(a>0) bt(ans+'(', a-1, b+1, n);
        if(b>0) bt(ans+')', a, b-1, n);
    }
    
    vector<string> generateParenthesis(int n) {
        bt("", n, 0, n);
        
        return res;
    }
};