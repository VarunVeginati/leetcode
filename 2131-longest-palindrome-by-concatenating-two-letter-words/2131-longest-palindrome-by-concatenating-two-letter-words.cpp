class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        
        for(int i=0; i<words.size(); i++) {
            m[words[i]]++;
        }
        
        int res = 0;
        bool flag = false;
        
        for(int i=0; i<words.size(); i++) {
            string rev =words[i];
            reverse(rev.begin(), rev.end());
            
            if(words[i]==rev) {
                if(m[rev]>0) {
                    if(m[rev]%2 == 0) {
                        res += m[rev]*2;
                        m.erase(rev);
                    } else {
                        res += (m[rev]-1)*2;
                        m[rev] = 1;
                        if(!flag) {
                            res += 2;
                            m.erase(rev);
                            flag = true;
                        }
                    }
                }
            } else if(m[rev]>0 && m[words[i]]>0) {
                res += 4;
                m[words[i]]--;
                m[rev]--;
            }
        }
        
        return res;
    }
};