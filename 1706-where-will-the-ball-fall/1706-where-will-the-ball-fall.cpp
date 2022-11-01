class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return -1;
        
        if(grid[i][j] == 1) {
            if(j == grid[0].size()-1) return -1;
            if(grid[i][j+1] != 1) return -1;
            
            if(i==grid.size()-1) return j+1>=grid[0].size() ? -1:j+1;
            
            return dfs(grid, i+1, j+1);
        } else {
            if(j == 0) return -1;
            if(grid[i][j-1] != -1) return -1;
            
            if(i==grid.size()-1) return j-1<0 ? -1:j-1;
            
            return dfs(grid, i+1, j-1);
        }
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        
        for(int i=0; i<grid[0].size(); i++) {
            res.push_back(dfs(grid, 0, i));
        }
        
        return res;
    }
};