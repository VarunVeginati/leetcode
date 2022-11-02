class Solution {
public:
    bool isOpeningBracket(char c) {
        return c=='(' || c=='[' || c=='{';
    }
    
    char getClosingBracket(char c) {
        if(c=='(') return ')';
        if(c=='[') return ']';
        
        return '}';
    }
    
    bool isValid(string s) {
        stack<char> st;
        
        for(int i=0; i<s.length(); i++) {
            if(isOpeningBracket(s[i])) st.push(s[i]);
            else {
                if(st.empty()) return false;
                if(getClosingBracket(st.top()) != s[i]) return false;
                
                st.pop();
            }
        }
        
        return st.empty();
    }
};