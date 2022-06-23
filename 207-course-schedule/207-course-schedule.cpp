class TopologicalOrder{
private:
    vector<vector<int>> edges;
    vector<int> indegree;
    vector<int> order;
    queue<int> q;
    bool isPossible = true;
    
public:
    TopologicalOrder(vector<vector<int>> graph, int numCourses) {
        indegree = vector<int>(numCourses, 0);
        edges = vector<vector<int>>(numCourses);
        
        for(int i=0; i<graph.size(); i++) {
            edges[graph[i][1]].push_back(graph[i][0]);
            indegree[graph[i][0]]++;
        }
    }
    
    void buildOrder() {
        for(int i=0; i<indegree.size(); i++)
            if(indegree[i]==0) q.push(i);
        
        while(!q.empty()) {
            int curr = q.front();
            order.push_back(curr);
            q.pop();
            
            vector<int> adjacentNodes = edges[curr];
            
            for(int node: adjacentNodes) {
                if(indegree[node] == 0) {
                    isPossible = true;
                    break;
                }
                indegree[node]--;
                if(indegree[node] == 0)
                    q.push(node);
            }
        }
    }
    
    bool hasOrder() {
        for(int i=0; i<indegree.size();i++) {
            if(indegree[i] != 0) {
                isPossible = false;
                break;
            }
        }
        
        return isPossible;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        TopologicalOrder tO = TopologicalOrder(prerequisites, numCourses);
        tO.buildOrder();
        return tO.hasOrder();
    }
};