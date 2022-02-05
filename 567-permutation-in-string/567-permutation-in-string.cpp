class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        
        map<char,int> s1m;
        map<char,int> s2m;
        
        for(char i='a'; i<='z'; i++) {
            s1m[i] = 0;
            s2m[i] = 0;
        }
        
        for(int i=0; i<s1.length(); i++)
            s1m[s1[i]]++;
        
        for(int i=0; i<s1.length(); i++)
            s2m[s2[i]]++;
        
        if(s1m==s2m) return true;
        
        for(int i=0; i<s2.length()-s1.length()+1; i++) {
            s2m[s2[i]]--;
            s2m[s2[i+s1.length()]]++;
            
            if(s1m==s2m) return true;
        }
        
        return false;
    }
};