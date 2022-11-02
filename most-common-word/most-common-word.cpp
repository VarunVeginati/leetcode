class Solution {
public:
    string tolowercase(string s) {
        for(int i=0; i<s.length(); i++)
            s[i] = tolower(s[i]);
        
        return s;
    }
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> banned_set;
        string res = "";
        int mx_occurrance = 0;
        unordered_map<string,int> m;
        
        for(int i=0; i<banned.size(); i++)
            banned_set.insert(tolowercase(banned[i]));
        
        string s = "";
        
        for(int i=0; i<paragraph.length(); i++) {
            if(tolower(paragraph[i])-'a'>=0 && tolower(paragraph[i])-'a'<26) {
                s += tolower(paragraph[i]);
            } else {
                if(s.length()>0 && banned_set.find(s) == banned_set.end()) {
                    m[s]++;
                    if(m[s]>mx_occurrance) {
                        mx_occurrance = m[s];
                        res = s;
                    }
                }
                
                s = "";
            }
        }
        
        if(s.length()>0 && banned_set.find(s) == banned_set.end()) {
            m[s]++;
            if(m[s]>mx_occurrance) {
                mx_occurrance = m[s];
                res = s;
            }
        }
        
//         for(auto it: m)
//             cout << it.first << "-" << it.second << endl;
        
        return res;
    }
};