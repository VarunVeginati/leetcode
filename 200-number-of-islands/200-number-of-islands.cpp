class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int,int> > directions = {
            make_pair(0,1),
            make_pair(0,-1),
            make_pair(1,0),
            make_pair(-1,0)
        };
        
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int> > q;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='1') {
                    grid[i][j] = '0';
                    cnt++;
                    q.push(make_pair(i,j));
                }
                
                while(!q.empty()) {
                    pair<int,int> curr = q.front();
                    q.pop();
                    
                    for(pair<int,int> direction : directions) {
                        int r = curr.first + direction.first;
                        int c = curr.second + direction.second;
                        
                        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]=='0') continue;
                        
                        grid[r][c] = '0';
                        q.push(make_pair(r,c));
                    }
                }
            }
        }
        
        return cnt;
    }
};