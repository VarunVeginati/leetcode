class Solution {
public:
    static pair<bool,string> isLetterLog(string s) {
        bool flag = false;
        string iden = "";
        
        for(int i=0; i<s.length(); i++) {
            if(flag) {
                if(s[i]-'a' >=0 && s[i]-'a'<=26) return make_pair(false, iden);
                else return make_pair(true, iden);
            } else if(s[i]==' ') flag = true;
            else {
                iden += s[i];
            }
        }
        
        return make_pair(false, "");
    }
    
    static bool comp(string a, string b) {
        string a_iden = isLetterLog(a).second;
        string b_iden = isLetterLog(b).second;
        
        a = a.substr(a_iden.length()+1);
        b = b.substr(b_iden.length()+1);
        
        return a==b ? a_iden<b_iden : a<b;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter_logs;
        vector<string> digi_logs;
        
        string lI = "";
        string dI = "";
        
        for(int i=0; i<logs.size(); i++) {
            if(!isLetterLog(logs[i]).first) {
                letter_logs.push_back(logs[i]);
            } else {
                digi_logs.push_back(logs[i]);
            }
        }
        
        sort(letter_logs.begin(), letter_logs.end(), comp);
        
        for(int i=0; i<digi_logs.size(); i++) {
            letter_logs.push_back(digi_logs[i]);
        }
        
        return letter_logs;
    }
};