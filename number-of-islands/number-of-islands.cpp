class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int,int>> directions = {
            make_pair(0,1),make_pair(0,-1),
            make_pair(1,0),make_pair(-1,0)
        };
        
        int res = 0;
        queue<pair<int,int>> q;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='0') continue;
                
                res++;
                q.push(make_pair(i,j));
                grid[i][j]='0';
                
                while(!q.empty()) {
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    
                    for(pair<int,int> direction: directions) {
                        int r = row + direction.first;
                        int c = col + direction.second;
                        
                        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]=='0') continue;
                        
                        grid[r][c] = '0';
                        q.push(make_pair(r,c));
                    }
                }
            }
        }
        
        return res;
    }
};