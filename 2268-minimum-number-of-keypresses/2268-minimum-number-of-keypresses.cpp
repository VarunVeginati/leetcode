class Solution {
public:
    int minimumKeypresses(string s) {
        vector<int> letter_count(26,0);
        
        for(char c: s) {
            letter_count[c-'a']++;
        }
        
        sort(letter_count.begin(), letter_count.end(), greater<int>());
        int ans = 0;
        
        for(int i=0; i<9; i++) {
            ans += letter_count[i];
        }
        
        for(int i=9; i<18; i++) {
            ans += letter_count[i]*2;
        }
        
        for(int i=18; i<26; i++) {
            ans += letter_count[i]*3;
        }
        
        
        return ans;
    }
};