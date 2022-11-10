class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visited;
        unordered_set<string> words;
        
        for(string word: wordList) words.insert(word);
        
        queue<string> q;
        q.push(beginWord);
        int step = 1;
        
        while(!q.empty()) {
            int size = q.size();
            step++;
            
            for(int j=0; j<size; j++) {
                string s = q.front();
                q.pop();
                
                for(int i=0; i<s.length(); i++) {
                    char c = s[i];
                    for(char rc='a'; rc<='z'; rc++) {
                        if(c!=rc) {
                            s[i]=rc;
                            if(words.find(s) != words.end() 
                               && visited.find(s)==visited.end()) {
                                if(s==endWord) return step;
                                visited.insert(s);
                                q.push(s);
                            }
                        }
                    }
                    s[i]=c;
                }
            }
        }
        
        return 0;
    }
};