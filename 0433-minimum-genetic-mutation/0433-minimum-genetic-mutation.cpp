class Solution {
public:
    set<string> bank_set;
    set<string> visited;
    int res = INT_MAX;
    vector<char> char_vec = {'A', 'C', 'G', 'T'};
    
    void bt(int level, string start, string end) {
        if(bank_set.find(start) == bank_set.end()) return;
        if(visited.find(start) != visited.end()) return;
        
        if(start == end) {
            res = min(res, level);
            return;
        }
        
        visited.insert(start);
        
        for(int i=0; i<8; i++) {
            for(char ch: char_vec) {
                char c = start[i];
                start[i] = ch;
                bt(level+1, start, end);
                start[i] = c;
            }
        }
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        for(string s: bank)
            bank_set.insert(s);
        
        bank_set.insert(start);
        
        if(bank_set.find(end) == bank_set.end()) return -1;
        
        bt(0, start, end);
        
        return res==INT_MAX?-1:res;
    }
};