class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length()<p.length()) return {};
        int pl = p.length();
        vector<int> vec;
        map<char, int> pm;
        map<char,int> sm;
        
        for(char i='a'; i<='z'; i++) {
            pm[i] = 0;
            sm[i] = 0;
        }
        
        for(int i=0; i<pl; i++)
            pm[p[i]]++;
        
        for(int i=0; i<pl; i++)
            sm[s[i]]++;
        
        if(pm==sm) vec.push_back(0);
        
        
        for(int i=0; i<s.length()-pl+1; i++) {
            sm[s[i]]--;
            sm[s[pl+i]]++;
            
            if(pm==sm) vec.push_back(i+1);
        }
        
        return vec;
    }
};