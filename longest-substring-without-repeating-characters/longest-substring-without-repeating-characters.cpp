class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int res = 0;
        int l = 0;
        
        for(int i=0; i<s.length(); i++) {
            if(m.find(s[i]) != m.end()) l = max(l, m[s[i]]+1);
            
            res = max(res, i-l+1);
            
            m[s[i]]=i;
        }
        
        return res;
    }
};