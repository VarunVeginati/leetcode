class Solution {
public:
    int minDeletions(string s) {
        vector<int> vec(26,0);
        map<int,int> m;
        
        for(int i=0; i<s.length(); i++) {
            vec[s[i]-'a']++;
        }
        
        int res=0;
        
        for(int i=0; i<26; i++) {
            if(vec[i]==0) continue;
            while(vec[i]!=0 && m.find(vec[i]) != m.end()) {
                vec[i]--;
                res++;
            }
            m[vec[i]]++;
        }
        
        return res;
    }
};