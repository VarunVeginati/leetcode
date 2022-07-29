class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<int> color(n, -1);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                q.push(i);
                color[i] = 1;
                while(!q.empty())
                {
                    int s = q.front();
                    q.pop();
                    visited[s]=true;
                    for(int j=0;j<graph[s].size();j++)
                    {
                        if(color[s]==color[graph[s][j]])
                            return false;
                        else if(color[graph[s][j]]==-1)
                        {
                            color[graph[s][j]] = 1-color[s];
                            q.push(graph[s][j]);
                        }
                    }
                }
            }
        }
        return true;
    }
};