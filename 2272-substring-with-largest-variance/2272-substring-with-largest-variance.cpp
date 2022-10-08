class Solution {
public:
    int getMax(string &s, char c1, char c2) {
        int f1 = 0;
        int f2 = 0;
        int ans = 0;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i]==c1) f1++;
            if(s[i]==c2) f2++;

            if(f1<f2) {
                f1=0;
                f2=0;
            }

            if(f1>f2 && f1>0 && f2>0) {
                ans = max(ans, f1-f2);
            }
        }
        
        return ans;
    }
    
    int largestVariance(string s) {
        vector<int> vec(26,0);
        int ans = 0;
        
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        for(int i=0; i<s.length(); i++) {
            vec[s[i]-'a']++;
        }
        
        for(char c1='a'; c1<='z'; c1++) {
            if(vec[c1-'a']==0) continue;
            for(char c2='a'; c2<='z'; c2++) {
                if(vec[c2-'a']==0) continue;
                
                ans = max(ans, getMax(s, c1, c2));
                ans = max(ans, getMax(rev_s, c1, c2));
            }
        }
        
        return ans;
    }
};