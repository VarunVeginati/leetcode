class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int res = 0;
        int i=0;
        
        while(i<s.length()-1) {
            if(m[s[i+1]]>m[s[i]]) {
                res += m[s[i+1]]-m[s[i]];
                i++;
            } else {
                res += m[s[i]];
            }
            
            i++;
        }
        
        if(i<s.length())
            res += m[s[i]];
        
        return res;
    }
};