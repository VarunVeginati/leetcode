class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<pair<int,int> > directions = {
            make_pair(0,1), make_pair(0,-1),
            make_pair(1,0), make_pair(-1,0)
        };
        
        vector<vector<int>> res = vector<vector<int>>(m, vector<int>(n,0));;
        queue<pair<int,int> > q;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j]==0) q.push(make_pair(i,j));
                else res[i][j]=INT_MAX;
            }
        }
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(pair<int,int> direction: directions) {
                int r = row+direction.first;
                int c = col+direction.second;
                
                if(r<0 || c<0 || r>=m || c>=n || res[r][c] != INT_MAX)
                    continue;
                
                res[r][c] = 1+res[row][col];
                q.push(make_pair(r,c));
            }
        }
        
        return res;
    }
};