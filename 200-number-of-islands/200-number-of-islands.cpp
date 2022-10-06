class Solution {
public:
    vector<pair<int,int>> directions = {
        make_pair(1,0), make_pair(-1,0),
        make_pair(0,1), make_pair(0,-1)
    };
    
    void dfs(vector<vector<char>>& grid, int r, int c) {
        for(pair<int,int> direction: directions) {
            int row = r+direction.first;
            int col = c+direction.second;
            
            if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]=='0')
                continue;
            
            grid[row][col] = '0';
            dfs(grid, row, col);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]=='1') {
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        
        return res;
    }
};