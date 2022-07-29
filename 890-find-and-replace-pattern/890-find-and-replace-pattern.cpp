class Solution {
private:
    string pat;
    
public:
    bool isMatched(string str) {
        map<char,char> m;
        map<char,char> m2;
        bool flag = true;

        for(int j=0; j<pat.length(); j++) {
            if(m.find(pat[j]) == m.end()) {
                if(m2.find(str[j])==m2.end()) {
                    m[pat[j]] = str[j];
                    m2[str[j]] = pat[j];
                } else {
                    flag = false;
                    break;
                }
            } else if(m[pat[j]] != str[j]){
                flag = false;
                break;
            }
        }

        return flag;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        pat = pattern;
        
        for(int i=0; i<words.size(); i++) {
            if(isMatched(words[i])) {
                res.push_back(words[i]);
            }
        }
        
        return res;
    }
};