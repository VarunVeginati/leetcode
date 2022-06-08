class Solution {
public:
    int removePalindromeSub(string s) {
        string str = s;
        reverse(str.begin(), str.end());
        
        return s==str ? 1 : 2;
    }
};