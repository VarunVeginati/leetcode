class TopoSort{
private:
    vector<vector<int>> vec;
    vector<int> indegree;
    int nd = 0;
    bool flag = true;
    
public:
    TopoSort(int n, vector<vector<int>>& prerequisites) {
        vec = vector<vector<int>>(n);
        indegree = vector<int>(n, 0);
        
        for(int i=0; i<prerequisites.size(); i++) {
            vec[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
    }
    
    void processNodes(int n) {
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i]==0) {
                nd++;
                q.push(i);
            }
        }
        
        while(!q.empty() && flag) {
            int curr = q.front();
            q.pop();
            
            vector<int> adj = vec[curr];
            
            for(int i=0; i<adj.size(); i++) {
                if(indegree[adj[i]]==0) {
                    flag = false;
                    break;
                }
                
                indegree[adj[i]]--;
                
                if(indegree[adj[i]]==0) {
                    nd++;
                    q.push(adj[i]);
                }
            }
        }
    }
    
    bool isPossible(int n) {
        return flag && n==nd;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        TopoSort tp = TopoSort(numCourses, prerequisites);
        tp.processNodes(numCourses);
        
        return tp.isPossible(numCourses);
    }
};