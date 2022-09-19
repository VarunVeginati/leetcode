class Solution {
public:
    vector<string> getContent(string s) {
        vector<string> vec;
        bool start = false;
        string str = "";
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ')') {
                start = false;
                vec.push_back(str);
                str = "";
            }
            
            if(start) {
                str += s[i];
            }
            
            if(s[i]=='(') {
                start = true;
            }
        }
        
        return vec;
    }
    
    vector<string> getFiles(string s) {
        vector<string> vec;
        bool start = false;
        string str = "";
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                start = false;
                vec.push_back(str);
                str = "";
            }
            
            if(start) {
                str += s[i];
            }
            
            if(s[i]==' ') {
                start = true;
            }
        }
        
        return vec;
    }
    
    string getPath(string s) {
        string str = "";
        
        for(int i=0; i<s.length(); i++) {
            if(s[i]==' ') return str+'/';
            str += s[i];
        }
        
        return "";
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> m;
        
        for(int i=0; i<paths.size(); i++) {
            vector<string> contents = getContent(paths[i]);
            vector<string> files = getFiles(paths[i]);
            string path = getPath(paths[i]);
            
            for(int i=0; i<contents.size(); i++) {
                m[contents[i]].push_back(path+files[i]);
            }
        }
        
        vector<vector<string>> res;
        
        for(auto it:m)  {
            if(it.second.size()>=2)
                res.push_back(it.second);
        }
        
        return res;
    }
};