class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str = "";
        
        for(int i=0; i<s.length(); i++) {
            str += s[i];
            int len = str.length();
            int j = i+1;
            
            while(str == s.substr(j, len) && j<s.length()) {
                j = j+len;
                if(j ==s.length()) return true;
            }
        }
        
        return false;
    }
};