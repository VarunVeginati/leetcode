class Solution {
public:
    char getUpperCase(char c) {
        return c-'a'+'A';
    }
    
    string makeGood(string s) {
        if(s.length()==0) return "";
        
        for(int i=0; i<s.length()-1; i++) {
            if(s[i+1]==getUpperCase(s[i]) || s[i] == getUpperCase(s[i+1])) {
                if(s.length()<=i+2) return makeGood(s.substr(0,i));
                return makeGood(s.substr(0,i)+s.substr(i+2));
            }
        }
        
        return s;
    }
};