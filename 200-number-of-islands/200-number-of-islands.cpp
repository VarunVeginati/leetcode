class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int,int>> directions = {
          make_pair(1,0), make_pair(-1,0),
            make_pair(0,-1), make_pair(0,1)
        };
        
        queue<pair<int,int>> q;
        int res = 0;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]=='1') {
                    q.push(make_pair(i,j));
                    grid[i][j] = '0';
                    res++;
                }
                
                
                while(!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    
                    for(pair<int,int> direction: directions) {
                        int row = r+direction.first;
                        int col = c+direction.second;
                        
                        if(row<0 || col <0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]=='0') continue;
                        grid[row][col] = '0';   
                        q.push(make_pair(row, col));
                    }
                }
            }
        }
        
        return res;
    }
};