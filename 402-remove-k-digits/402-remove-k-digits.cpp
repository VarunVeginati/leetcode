class Solution {
public:
    string removeLeadingZeros(string num) {
        int i=0;
        while(num[i]=='0') {
            i++;
        }
        return num.substr(i);
    }
    
    string removeKdigits(string num, int k) {
        if(num.length()==k) return "0";
        if(k==0 || num.length()<=1) {
            string s = removeLeadingZeros(num);
            if(s=="") return "0";
            else return s;
        }
        
        stack<char> st;
        
        st.push(num[0]);
        
        for(int i=1; i<num.length(); i++) {
            while(!st.empty() && num[i]<st.top() && k>0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        string s = "";
        
        while(k>0) {
            st.pop();
            k--;
        }
        
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        
        reverse(s.begin(), s.end());
        
        s = removeLeadingZeros(s);
        
        if(s=="") return "0";
        else return s;
    }
};