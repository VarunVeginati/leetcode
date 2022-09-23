class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j = 0;
        int mx = 0;
        map<char,int> m;
        
        for(int i=0; i<s.length(); i++) {
            if(m.find(s[i]) != m.end() && m[s[i]]>=j) {
                j = m[s[i]]+1;
                m[s[i]] = i;
            } else {
                m[s[i]] = i;
            }
            mx = max(mx, i-j+1);
        }
        
        return mx;
    }
};