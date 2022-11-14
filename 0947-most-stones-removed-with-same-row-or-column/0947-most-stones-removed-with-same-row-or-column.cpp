class UnionFind{
private:
    vector<int> rank;
    vector<int> root;
    int cnt;
    
public:
    UnionFind(int n) {
        cnt = n;
        for(int i=0; i<n; i++) {
            rank.push_back(1);
            root.push_back(i);
        }
    }
    
    int find(int x) {
        if(x==root[x]) return x;
        return root[x]=find(root[x]);
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
            
            cnt--;
        }
    }
    
    int totalComponents() {
        return cnt;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf = UnionFind(n);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    uf.connectNodes(i,j);
                }
            }
        }
        
        return n-uf.totalComponents();
    }
};