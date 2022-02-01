class Solution {
public:
    
    int calculate(string s) {
        vector<string> vec;
        string str = "";
        
        for(int i=0; i<s.length(); i++) {
            if(s[i]!='/' && s[i]!='*' && s[i]!='-' && s[i]!='+') {
                if(s[i] != ' ')
                    str += s[i];
            }
            else {
                vec.push_back(str);
                string c = "";
                c = c+s[i];
                vec.push_back(c);
                str = "";
            }
        }
        
        vec.push_back(str);
        
        for(int i=0; i<vec.size(); i++) {
            if(vec[i] == "/") {
                int a = stoi(vec[i-1]);
                int b = stoi(vec[i+1]);
                vec[i-1] = to_string(a/b);
                vec.erase(vec.begin()+i, vec.begin()+i+2);
                i--;
            } else if(vec[i] == "*") {
                int a = stoi(vec[i-1]);
                int b = stoi(vec[i+1]);
                vec[i-1] = to_string(a*b);
                vec.erase(vec.begin()+i, vec.begin()+i+2);
                i--;
            }
        }
        
        for(int i=0; i<vec.size(); i++)
            cout << vec[i] << " ";
        
        int res = stoi(vec[0]);
        
        for(int i=1; i<vec.size(); i++) {
            if(vec[i] == "+") {
                res += stoi(vec[i+1]);
            } else {
                res -= stoi(vec[i+1]);
            }
            i++;
        }
        
        return res;
    }
};