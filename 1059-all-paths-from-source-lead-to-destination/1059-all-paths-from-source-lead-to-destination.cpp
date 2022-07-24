class DFS {
private:
    vector<int> visited;
    vector<vector<int>> edges_map;
    int destination;
    bool loopPresent = false;
    bool possible = true;
    
public:
    DFS(vector<vector<int>> edges, int n, int dest) {
        destination = dest;
        edges_map = vector<vector<int>>(n);
        visited = vector<int>(n, 0);
        
        for(int i=0; i<edges.size(); i++) {
            edges_map[edges[i][0]].push_back(edges[i][1]);
        }
    }
    
    void recursion(int source, vector<int> path) {
        if(loopPresent || !possible) return;
        
        visited[source] = 1;
        vector<int> adjacentNodes = edges_map[source];
        int count = 0;
        
        for(int i=0; i<adjacentNodes.size(); i++) {
            if(visited[adjacentNodes[i]] == 0) {
                count++;
                path.push_back(adjacentNodes[i]);
                recursion(adjacentNodes[i], path);
                path.pop_back();
            } else {
                loopPresent = true;
                break;
            }
        }
        
        if(count==0 && path.back()!=destination) {
            possible = false;
        }
        
        visited[source] = 0;
    }
    
    bool isPossible(int destination) {        
        return !loopPresent && possible;
    }
    
};

class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        DFS dfs(edges, n, destination);
        
        dfs.recursion(source, {source});
        
        return dfs.isPossible(destination);
    }
};