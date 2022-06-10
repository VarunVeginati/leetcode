class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int longest = 0;
        
        int current = 0;
        
        for(int i=0; i<s.length(); i++) {
            if(m.find(s[i]) != m.end()) {
                current = max(m[s[i]], current);
            }
            longest = max(longest, i-current+1);
            m[s[i]] = i+1;
        }
        
        return longest;
    }
};