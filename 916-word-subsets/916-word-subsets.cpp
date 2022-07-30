class Solution {
public:
    bool isSubString(string s, vector<int> vec) {
        map<int,int> m;
        for(int i=0; i<s.length(); i++) {
            m[s[i]-'a']++;
        }
        
        for(int i=0; i<26; i++) {
            if(vec[i]>m[i]) return false;
        }
        
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> m(26,0);
        
        for(int i=0; i<words2.size(); i++) {
            vector<int> vec(26,0);
            for(int j=0; j<words2[i].length(); j++) {
                vec[words2[i][j]-'a']++;
            }
            
            for(int j=0; j<26; j++) {
                m[j] = max(m[j], vec[j]);
            }
        }
        
        vector<string> res;
        
        for(int i=0; i<words1.size(); i++) {
            if(isSubString(words1[i], m)) {
                res.push_back(words1[i]);
            }
        }
        
        return res;
    }
};