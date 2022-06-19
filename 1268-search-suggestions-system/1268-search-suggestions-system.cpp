class Trie{
private:
	struct Node {
		bool isWord = false;
		vector<Node*> children{vector<Node*>(26, NULL)};
	} *Root, *curr;

	void dfs(Node* curr, string &word, vector<string> &result) {
		if(result.size()==3) return;

		if(curr->isWord) result.push_back(word);

		for(char c='a'; c<='z'; c++) {
			if(curr->children[c-'a'] != NULL) {
				word += c;
				dfs(curr->children[c-'a'], word, result);
				word.pop_back();
			}
		}
	}

public:
	Trie() {
		Root = new Node();
	}

	void insert(string s) {
		curr = Root;

		for(char c: s) {
			if(curr->children[c-'a'] == NULL)
				curr->children[c-'a'] = new Node();
			curr = curr->children[c-'a'];
		}

		curr->isWord = true;
	}

	vector<string> getWordStartingWith(string prefix) {
		curr = Root;
		vector<string> result;

		for(char c: prefix) {
			if(curr->children[c-'a']==NULL)
				return result;
			curr = curr->children[c-'a'];
		}
		dfs(curr, prefix, result);
		return result;
	}
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie = Trie();

        for(string word: products)
            trie.insert(word);
        
        vector<vector<string>> result;

        string prefix="";

        for(char c: searchWord) {
            prefix += c;
            result.push_back(trie.getWordStartingWith(prefix));
        }
        
        return result;
    }
};