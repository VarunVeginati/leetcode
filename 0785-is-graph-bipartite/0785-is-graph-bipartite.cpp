class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vec(n, 0);
        queue<int> q;
        
        for(int i=0; i<n; i++) {
            if(vec[i]==0) q.push(i);
            
            int a = 1;
            vec[i] = a;
            
            while(!q.empty()) {
                a = a*-1;
                int size = q.size();

                for(int i=0; i<size; i++) {
                    int curr = q.front();
                    q.pop();

                    vector<int> adj = graph[curr];

                    for(int j=0; j<adj.size(); j++) {
                        if(vec[adj[j]]==0) vec[adj[j]]=a;
                        else if(vec[adj[j]]==a) continue;
                        else return false;

                        q.push(adj[j]);
                    }
                }
            }
        }
        
        return true;
    }
};