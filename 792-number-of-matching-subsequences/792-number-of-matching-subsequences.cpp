class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> letterPositions(26);
        
        for(int i=0; i<s.length(); i++) {
            letterPositions[s[i]-'a'].push_back(i);
        }
        
        int cnt = 0;
        
        for(int i=0; i<words.size(); i++) {
            string str = words[i];
            vector<int> last(26,0);
            bool matching = true;
            if(letterPositions[str[0]-'a'].size()==0)
                continue;
            
            int lastOccurrence = letterPositions[str[0]-'a'][last[str[0]-'a']];
            last[str[0]-'a']++;
            for(int j=1; j<str.length(); j++) {
                 while(letterPositions[str[j]-'a'].size()>last[str[j]-'a'] && letterPositions[str[j]-'a'][last[str[j]-'a']] <= lastOccurrence) {
                    last[str[j]-'a']++;
                }
                if(letterPositions[str[j]-'a'].size()<=last[str[j]-'a']) {
                    matching = false;
                    break;
                }
                if(letterPositions[str[j]-'a'][last[str[j]-'a']] <= lastOccurrence) {
                    matching = false;
                    break;
                }
                lastOccurrence = letterPositions[str[j]-'a'][last[str[j]-'a']];
                last[str[j]-'a']++;
            }
            
            if(matching) {
                cout << words[i] << endl;
                cnt++;
            }
        }
        
        return cnt;
    }
};