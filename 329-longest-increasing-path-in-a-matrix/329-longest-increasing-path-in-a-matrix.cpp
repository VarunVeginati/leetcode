class Solution {
private:
    int m;
    int n;
    vector<vector<int>> max_vec;
    vector<vector<int>> mat;
    vector<pair<int,int> > directions = {
        make_pair(0,1),
        make_pair(0,-1),
        make_pair(1,0),
        make_pair(-1,0)
    };
    
public:
    int dfs(int i, int j) {
        if(max_vec[i][j] != -1) return max_vec[i][j];
        
        int mx = 0;
        
        for(pair<int,int> direction : directions) {
            int row = i+direction.first;
            int col = j+direction.second;
            
            if(row<0 || col<0 || row>=m || col>=n || mat[row][col]<=mat[i][j]) continue;
            
            mx = max(mx, 1+dfs(row,col));
        }
        
        max_vec[i][j] = mx;
        
        return mx;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        mat = matrix;
        max_vec = vector<vector<int>>(m, vector<int>(n, -1));
        
        int mx = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(max_vec[i][j] != -1) continue;
                
                mx = max(mx, dfs(i,j));
            }
        }
        
        return 1+mx;
    }
};