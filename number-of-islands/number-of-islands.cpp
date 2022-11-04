class Solution {
public:
    int m;
    int n;
    
    vector<pair<int,int>> directions = {
        make_pair(0,1),make_pair(0,-1),
        make_pair(1,0),make_pair(-1,0)
    };
    
    void dfs(vector<vector<char>> & grid, int i, int j) {
        for(pair<int,int> direction: directions) {
            int r = direction.first+i;
            int c = direction.second+j;
            
            if(r<0 || c<0 || r>=m || c>=n || grid[r][c]=='0') continue;
            
            grid[r][c] = '0';
            
            dfs(grid, r, c);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return res;
    }
};