class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_j = 0;
        
        for(int i=0; i<t.length(); i++) {
            if(s_j >= s.length()) return true;
            if(s[s_j] == t[i])
                s_j++;
        }
        
        return s_j>=s.length();
    }
};