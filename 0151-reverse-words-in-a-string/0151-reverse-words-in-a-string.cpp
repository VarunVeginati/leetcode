class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        
        string str = "";
        
        for(int i=0; i<s.length(); i++) {
            if(s[i]==' ') {
                if(str.length()>0) {
                    vec.push_back(str);
                    str = "";
                }
            } else {
                str+=s[i];
            }
        }
        
        if(str.length()>0) vec.push_back(str);
        
        string res = "";
        
        for(int i=vec.size()-1; i>=0; i--) {
            res += vec[i];
            if(i!=0) res+=' ';
        }
        
        return res;
    }
};