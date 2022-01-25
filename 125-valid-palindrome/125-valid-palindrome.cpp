class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        
        for(int i=0; i<s.length(); i++) {
            if(isalnum(s[i]))
                str += tolower(s[i]);
        }
        
        int l;
        int r;
        
        if(str.length()%2==0) {
            l=(str.length()/2)-1;
            r=str.length()/2;
        } else {
            l=r=str.length()/2;
        }
        
        while(l>=0 && r<str.length()) {
            if(str[l] != str[r]) return false;
            l--;
            r++;
        }
        
        return true;
    }
};