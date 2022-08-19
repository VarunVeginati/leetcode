class Dijkstras{
private:
    vector<vector<pair<int,int> >> edges;
    vector<pair<int,int> > table;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> >> pq;
    int visited_count = 0;
    vector<int> visited;
    int total_nodes;
    
public:
    Dijkstras(vector<vector<int>>& times, int n) {
        visited = vector<int>(n+1, 0);
        edges = vector<vector<pair<int,int> >>(n+1);
        table = vector<pair<int,int> >(n+1, make_pair(INT_MAX,INT_MAX));
        total_nodes = n;
        for(int i=0; i<times.size(); i++) {
            edges[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }
    }
    
    void generateTable(int k) {
        table[k] = make_pair(0,0);
        vector<pair<int,int> > neighbors = edges[k];
        for(int i=0; i<neighbors.size(); i++) {
            table[neighbors[i].first] = make_pair(neighbors[i].second, k);
            pq.push(make_pair(neighbors[i].second, neighbors[i].first));
        }
        visited_count++;
        visited[k]=1;
        
        while(pq.size()>0 && visited_count<total_nodes) {
            pair<int,int> top_node = pq.top();
            pq.pop();
            
            if(visited[top_node.second] == 1) continue;
            
            vector<pair<int,int> > neighbors = edges[top_node.second];
            
            for(int i=0; i<neighbors.size(); i++) {
                int a = top_node.first + neighbors[i].second;
                if(a < table[neighbors[i].first].first) {
                    table[neighbors[i].first] = make_pair(a, top_node.second);
                    pq.push(make_pair(a, neighbors[i].first));
                }
            }
            visited_count++;
            visited[top_node.second]=1;
        }
        
    }
    
    int getMax() {
        int res = 0;
        for(int i=1; i<table.size(); i++) {
            res = max(res, table[i].first);
        }
        
        return res!=INT_MAX?res:-1;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Dijkstras dk = Dijkstras(times, n);
        
        dk.generateTable(k);
        
        return dk.getMax();
    }
};