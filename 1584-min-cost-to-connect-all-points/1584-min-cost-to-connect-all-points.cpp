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
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                pq.push(make_pair(dist, make_pair(i,j)));
            }
        }
        
        UnionFind uf = UnionFind(points.size());
        int sum = 0;
        
        while(!pq.empty()) {
            if(uf.isConnected(pq.top().second.first, pq.top().second.second)) {
                pq.pop();
                continue;
            }
            
            sum += pq.top().first;
            uf.unionSet(pq.top().second.first, pq.top().second.second);
            
            pq.pop();
        }
        
        return sum;
    } 
};