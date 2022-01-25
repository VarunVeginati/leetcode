class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        
        for(int i=0; i<s.length(); i++) {
            if(s[i]>=65 && s[i]<=90) {
                str += tolower(s[i]);
            } else if((s[i]>=97 && s[i]<=122) 
                      || (s[i]>=48 && s[i]<=57) ) {
                str += s[i];
            }
        }
        
        string str_reverse = str;
        
        reverse(str.begin(), str.end());
        
        return str==str_reverse;
    }
};