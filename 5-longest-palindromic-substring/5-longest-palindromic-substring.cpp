class Solution {
public:
    int longestPalSeq(string s, int L, int R) {
        while(L>=0 && R<s.length() && s[L]==s[R]) {
            L--;
            R++;
        }
        
        return R-L-1;
    }
    
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        
        for(int i=0; i<s.length(); i++) {
            int l1 = longestPalSeq(s, i, i);
            int l2 = longestPalSeq(s, i, i+1);
            int len = max(l1, l2);
            
            if(len>end-start) {
                start = i-(len-1)/2;
                end = i+(len)/2;
            }
        }
        
        return s.substr(start, end-start+1);
    }
};