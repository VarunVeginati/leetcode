class TopologicalSort{
private:
    vector<vector<int>> edges;
    vector<int> indegree;
    vector<int> order;
    bool possible = true;
    
public:
    TopologicalSort(vector<vector<int>> &prerequisites, int n) {
        indegree = vector<int>(n ,0);
        edges = vector<vector<int>>(n);
        
        for(int i=0; i<prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
    }
    
    void generateOrder(int n) {
        queue<int> q;
        for(int i=0; i<n; i++)
            if(indegree[i]==0) q.push(i);
        
        while(!q.empty() && possible) {
            int curr = q.front();
            order.push_back(curr);
            q.pop();
            vector<int> adjacentNodes = edges[curr];
            
            for(int i=0; i<adjacentNodes.size(); i++) {
                if(indegree[adjacentNodes[i]] == 0) {
                    possible = false;
                    break;
                }
                
                indegree[adjacentNodes[i]]--;
                if(indegree[adjacentNodes[i]] == 0) q.push(adjacentNodes[i]);
            }
        }
    }
    
    bool isPossible(int n) {
        return order.size()==n && possible;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        TopologicalSort tp = TopologicalSort(prerequisites, numCourses);
        tp.generateOrder(numCourses);
        
        return tp.isPossible(numCourses);
    }
};