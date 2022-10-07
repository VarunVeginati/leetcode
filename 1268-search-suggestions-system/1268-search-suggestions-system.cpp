class Trie{
public:
    struct Node {
        bool isWord = false;
        vector<Node*> children = vector<Node*>(26,NULL);
    };
    
    Node* Root;
    
    Trie() {
        Root = new Node();
    }
    
    void addProduct(string s) {
        Node* curr = Root;
        
        for(int i=0; i<s.length(); i++) {
            if(curr->children[s[i]-'a'] == NULL)
                curr->children[s[i]-'a'] = new Node();
                
            curr = curr->children[s[i]-'a'];
        }
        
        curr->isWord = true;
    }
    
    void dfs(Node* curr, vector<string> &vec, string &str) {
        if(vec.size()>=3 || curr==NULL) return;
        if(curr->isWord) {
            vec.push_back(str);
        }
        
        for(char c='a'; c<='z'; c++) {
            if(curr->children[c-'a'] != NULL) {
                str += c;
                dfs(curr->children[c-'a'], vec, str);
                str.pop_back();
            }
        }
    }
    
    vector<string> getSuggestion(string s) {
        Node* curr = Root;
        vector<string> vec;
        
        for(int i=0; i<s.length(); i++) {
            if(curr==NULL) return vec;
            curr = curr->children[s[i]-'a'];
        }
        
        dfs(curr, vec, s);
        
        return vec;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        
        Trie trie = Trie();
        
        for(int i=0; i<products.size(); i++) {
            trie.addProduct(products[i]);
        }
        
        for(int i=0; i<searchWord.size(); i++) {
            res.push_back(trie.getSuggestion(searchWord.substr(0, i+1)));
        }
        
        return res;
    }
};