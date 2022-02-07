class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> vec(26,0);
        
        for(int i=0; i<s.length(); i++)
            vec[s[i]-'a'] += 1;
        
        for(int i=0; i<t.length(); i++) {
            if(vec[t[i]-'a'] == 0) return t[i];
            else vec[t[i]-'a'] -= 1;
        }
        
        return 'a';
    }
};