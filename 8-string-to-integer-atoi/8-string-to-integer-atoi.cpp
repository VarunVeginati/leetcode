class Solution {
public:
    bool is_valid_char(char c) {
        int a = (int)c - 48;
        return c=='+' || c=='-' || (a>=0 && a<=9);
    }
    
    int st_i(string s) {
        stringstream g(s);
        long int x=0;
        g>>x;
        
        if(x<-2147483648) return -2147483648;
        else if(x>2147483647) return 2147483647;
        return x;
    }
    
    int myAtoi(string s) {
        int i=0;
        
        while(i<s.length() && !is_valid_char(s[i])) {
            if((s[i]-'a'>=0 && s[i]-'a'<26) || s[i]=='.') return 0;
            i++;
        }
        
        string str="";
        
        while(i<s.length() && !((s[i]-'a'>=0 && s[i]-'a'<26) || s[i]=='.')) {
            str += s[i];
            i++;
        }
        
        return st_i(str);
    }
};