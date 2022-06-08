class UnionFind {
private:
    vector<int> root;
    vector<int> rank;
    
public:
    UnionFind(int size) {
        for(int i=0; i<size; i++) {
            root.push_back(i);
            rank.push_back(1);
        }
    }
    
    int find(int x) {
        if(x==root[x]) return x;
        
        return root[x]=find(root[x]);
    }
    
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY])
                root[rootY] = rootX;
            else if(rank[rootX] < rank[rootY])
                root[rootX] = rootY;
            else {
                root[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    
    bool isConnected(int x, int y) {
        return find(x)==find(y);
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> edges;
        
        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push({dist,i,j});
            }
        }
        
        int n = 0;
        int minCost = 0;
        
        UnionFind uf(points.size());
        
        while(!edges.empty()) {
            if(n == points.size()-1) return minCost;
            
            vector<int> top_node = edges.top();
            edges.pop();
            
            if(!uf.isConnected(top_node[1], top_node[2])) {
                uf.unionSet(top_node[1], top_node[2]);
                minCost += top_node[0];
                n++;
            }
        }
        
        return minCost;
    } 
};