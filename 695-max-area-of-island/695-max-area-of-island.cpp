class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<pair<int,int> > directions = {
            make_pair(0,1),
            make_pair(0,-1),
            make_pair(1,0),
            make_pair(-1,0)
        };
        
        queue<pair<int,int> > q;
        int m = grid.size();
        int n = grid[0].size();
        set<pair<int,int> > visited;
        int max_area = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) continue;
                if(visited.find(make_pair(i,j)) != visited.end()) continue;
                
                int area = 0;
                visited.insert(make_pair(i,j));
                q.push(make_pair(i,j));
                
                while(!q.empty()) {
                    area++;
                    for(pair<int,int> direction: directions) {
                        int r = q.front().first + direction.first;
                        int c = q.front().second  + direction.second;
                        
                        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]==0 ||
                           visited.find(make_pair(r,c)) != visited.end())
                            continue;
                        
                        visited.insert(make_pair(r,c));
                        q.push(make_pair(r,c));
                    }
                    
                    q.pop();
                }
                
                max_area = max(max_area, area);
            }
        }
        
        return max_area;
    }
};