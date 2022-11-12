class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for(int i=0; i<s.length(); i++) {
            if(st.empty() || st.top() != s[i]) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }
        
        string str = "";
        
        while(!st.empty()) {
            str += st.top();
            st.pop();
        }
        
        reverse(str.begin(), str.end());
        
        return str;
    }
};