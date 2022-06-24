class TopologicalOrder{
private:
    vector<vector<int>> edges;
    vector<int> indegree;
    queue<int> q;
    bool isPossible = true;
    int semesters = 0;
    
public:
    TopologicalOrder(vector<vector<int>> graph, int numCourses) {
        indegree = vector<int>(numCourses+1, 0);
        edges = vector<vector<int>>(numCourses+1);
        
        for(int i=0; i<graph.size(); i++) {
            edges[graph[i][0]].push_back(graph[i][1]);
            indegree[graph[i][1]]++;
        }
    }
    
    void buildOrder() {
        for(int i=1; i<indegree.size(); i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty() && isPossible) {
            int size = q.size();
            semesters++;
            
            for(int i=0; i<size; i++) {
                int curr = q.front();
                q.pop();

                vector<int> adjacentNodes = edges[curr];

                for(int node: adjacentNodes) {
                    if(indegree[node] == 0) {
                        isPossible = false;
                        break;
                    }
                    indegree[node]--;
                    if(indegree[node] == 0)
                        q.push(node);
                }
            }
        }
    }
    
    bool hasOrder() {
        for(int i=1; i<indegree.size();i++) {
            if(indegree[i] != 0) {
                isPossible = false;
                break;
            }
        }
        
        return isPossible;
    }
    
    int getSemesters() {
        return semesters;
    }
};

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        TopologicalOrder tO = TopologicalOrder(relations, n);
        tO.buildOrder();
        if(tO.hasOrder()) {
            return tO.getSemesters();
        } else {
            return -1;
        }
    }
};