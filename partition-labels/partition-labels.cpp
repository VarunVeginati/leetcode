class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> m;
        
        for(int i=0; i<s.length(); i++)
            m[s[i]]=i;
        
        vector<int> res;
        int mx = 0;
        int last = 0;
        
        for(int i=0; i<s.length(); i++) {
            mx = max(mx, m[s[i]]);
            if(i==s.length()-1 || i>=mx) {
                res.push_back(i+1 - last);
                last = i+1;
            }
        }
        
        return res;
    }
};