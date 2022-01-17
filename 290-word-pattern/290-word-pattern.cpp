class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> m;
        set<string> str_set;
        vector<string> vec;
        string str = "";
        
        for(char c: s) {
            if(c==' ') {
                vec.push_back(str);
                str = "";
            } else {
                str += c;
            }
        }
        vec.push_back(str);
        
        if(pattern.length() != vec.size()) return false;
        
        for(int i=0; i<pattern.length(); i++) {
            if(m.find(pattern[i]) != m.end()) {
                if(m[pattern[i]] != vec[i]) return false;
            } else {
                if(str_set.find(vec[i]) == str_set.end()) {
                    m[pattern[i]] = vec[i];
                    str_set.insert(vec[i]);
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};