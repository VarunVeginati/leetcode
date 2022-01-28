class WordDictionary {
public:
    map<int, vector<string>> m;
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        m[word.length()].push_back(word);
    }
    
    bool are_equal(string s, string w) {
        for(int i=0; i<s.length(); i++) {
            if(s[i]!=w[i] && w[i] != '.') return false;
        }
        return true;
    }
    
    bool search(string word) {
        vector<string> vec = m[word.length()];
        
        for(int i=0; i<vec.size(); i++) {
            string s = vec[i];
            if(are_equal(s, word)) return true;
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */