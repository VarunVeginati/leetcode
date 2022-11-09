class Solution {
public:
    bool isDigiLog(string s) {
        bool flag = false;
        
        for(int i=0; i<s.length(); i++) {
            if(flag) {
                if(s[i]-'0'>=0 && s[i]-'0'<=9) return true;
                else return false;
            }
            
            if(s[i]==' ') flag=true;
        }
        
        return false;
    }
    
    static int getIdentifierEndIndex(string s) {
        for(int i=0; i<s.length(); i++) {
            if(s[i]==' ') return i;
        }
        
        return -1;
    }
    
    static bool comp(string a, string b) {
        int a_idx = getIdentifierEndIndex(a);
        int b_idx = getIdentifierEndIndex(b);
        string a_identifier = a.substr(0, a_idx);
        string b_identifier = b.substr(0, b_idx);
        string a_content = a.substr(a_idx+1);
        string b_content = b.substr(b_idx+1);
        
        if(a_content==b_content) return a_identifier<b_identifier;
        
        return a_content<b_content;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digiLogs;
        vector<string> letterLogs;
        
        for(int i=0; i<logs.size(); i++) {
            if(isDigiLog(logs[i])) {
                digiLogs.push_back(logs[i]);
            } else {
                letterLogs.push_back(logs[i]);
            }
        }
        
        sort(letterLogs.begin(), letterLogs.end(), comp);
        
        for(int i=0; i<digiLogs.size(); i++) {
            letterLogs.push_back(digiLogs[i]);
        }
        
        return letterLogs;
    }
};