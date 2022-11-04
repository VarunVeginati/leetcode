class Solution {
public:
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u'
            || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    
    string reverseVowels(string s) {
        string str = "";
        
        for(int i=0; i<s.length(); i++)
            if(isVowel(s[i])) str += s[i];
        
        reverse(str.begin(), str.end());
        int p1 = 0;
        
        for(int i=0; i<s.length(); i++) {
            if(isVowel(s[i])) {
                s[i] = str[p1];
                p1++;
            }
        }
        
        return s;
    }
};