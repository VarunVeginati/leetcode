class UnionFind{
private:
    vector<int> root;
    vector<int> rank;
    
public:
    UnionFind() {
        for(int i=0; i<26; i++) {
            root.push_back(i);
            rank.push_back(1);
        }
    }
    
    int find(int x) {
        if(x==root[x]) return x;
        return root[x] = find(root[x]);
    }
    
    void connectNodes(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if(rank[rootY] > rank[rootX]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf = UnionFind();
        
        for(int i=0; i<equations.size(); i++) {
            if(equations[i][1] == '=' && equations[i][0] != equations[i][3]) {
                uf.connectNodes(equations[i][0]-'a', equations[i][3]-'a');
            }
        }
        
        for(int i=0; i<equations.size(); i++) {
            if(equations[i][1] == '!') {
                if(uf.find(equations[i][0]-'a') == uf.find(equations[i][3]-'a')) {
                    return false;
                }
            }
        }
        
        return true;
    }
};