class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int h = haystack.length();
        
        for(int i=0; i<h; i++) {
            if(haystack.substr(i, n) == needle) return i;
        }
        
        return -1;
    }
};