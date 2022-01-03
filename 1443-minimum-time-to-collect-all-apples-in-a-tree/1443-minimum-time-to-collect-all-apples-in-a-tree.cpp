class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        map<int,int> parent_node;
        map<int,int> child_node;
        
        for(int i=0; i<edges.size(); i++) {
            parent_node[edges[i][1]] = edges[i][0];
            child_node[edges[i][0]] = edges[i][1];
        }
        
        int cnt=0;
        vector<int> visited(n, 0);
        
        for(int i=0; i<hasApple.size(); i++) {
            if(hasApple[i]) {
                int parent = i;
                while(parent!=0 && visited[parent]==0) {
                    cnt += 2;
                    visited[parent]++;
                    if(parent_node.find(parent) != parent_node.end())
                        parent = parent_node[parent];
                    else
                        parent = child_node[parent];
                }
            }
        }
        
        return cnt;
    }
};