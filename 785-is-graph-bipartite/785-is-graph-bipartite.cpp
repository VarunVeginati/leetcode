class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vec(n, 0);
        set<int> visited;
        queue<int> q;
        
        for(int i=0; i<n; i++) {
            if(visited.find(i)!=visited.end()) continue;
            
            q.push(i);
            int a = 1;
            vec[i] = a;
            
            while(!q.empty()) {
                a=a*-1;
                int size = q.size();
                
                for(int i=0; i<size; i++) {
                    int curr = q.front();
                    q.pop();
                    
                    // vector<int> neighbours = graph[curr];
                    visited.insert(curr);
                    
                    for(int j=0; j<graph[curr].size(); j++) {
                        if(visited.find(graph[curr][j]) != visited.end()) continue;
                        
                        if(vec[graph[curr][j]]==0) vec[graph[curr][j]] = a;
                        else if(vec[graph[curr][j]] != a) return false;
                        
                        q.push(graph[curr][j]);
                    }
                }
            }
        }
        
        return true;
    }
};