class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        // sort(words.begin(), words.end(), [](const string &a, const string &b)->bool{
        //    return a.length()>b.length(); 
        // });
        
        set<string> s;
        
        for(int i=0; i<words.size(); i++) {
            s.insert(words[i]);
        }
        
        for(string str: words) {
            for(int j=1; j<str.length(); j++) {
                if(s.find(str.substr(j)) != s.end())
                    s.erase(str.substr(j));
            }
        }
        
        int sum = 0;
        
        for(string str : s) {
            sum += str.length()+1;
        }
        
        return sum;
    }
};