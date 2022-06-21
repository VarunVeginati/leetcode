class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b)->bool{
           return a.length()>b.length(); 
        });
        
        set<string> s;
        
        for(int i=0; i<words.size(); i++) {
            s.insert(words[i]);
        }
        
        int sum = 0;
        
        for(int i=0; i<words.size(); i++) {
            string str = words[i];
            if(s.find(str) == s.end()) continue;
            
            for(int j=0; j<str.length(); j++) {
                if(s.find(str.substr(j)) != s.end())
                    s.erase(str.substr(j));
            }
            
            sum += str.length()+1;
        }
        
        return sum;
    }
};