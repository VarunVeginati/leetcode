class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > m;
        
        for(string s: strs) {
            string a = s;
            sort(s.begin(), s.end());
            m[s].push_back(a);
        }
        
        vector<vector<string>> res;
        
        for(auto it: m) {
            res.push_back(it.second);
        }
        
        return res;
    }
};